#include <bits/stdc++.h>
using namespace std;
using P=pair<int, int>;
using PF=pair<float, float>;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define N 1000
int n, b;

int catId = 0;
unordered_map<string, int> catDic;
int CAT(const string& str)
{
    if(!catDic.count(str))
        catDic[str] = catId++;
    return catDic[str];
}
void init()
{
    catId = 0;
    catDic.clear();
}

struct C
{
    int p = 0;
    int q = 0;
    int cat = -1;

    friend bool operator<(const C &lhs, const C &rhs)
    {
        return lhs.q == rhs.q ? lhs.p < rhs.p : lhs.q < rhs.q;
    }
    friend bool operator>(const C &lhs, const C &rhs)
    {
        return lhs.q == rhs.q ? lhs.p > rhs.p : lhs.q > rhs.q;
    }
    friend ostream& operator<<(ostream &os, const C &c)
    {
        return os << "p=" << c.p << " q=" << c.q << " cat=" << c.cat;
    }
};

int main()
{
	int T;
    cin >> T;
    while(T-- && cin >> n >> b)
    {
        priority_queue<C, vector<C>, greater<C>> pq[N+5];
        init();
        //
        string in, ph;
        int p, q;
        for(int i = 0; i < n && cin >> in >> ph >> p >> q; i++)
        {
            int ci = CAT(in);
            pq[ci].push((C){p, q, ci});
        }
        //
        priority_queue<C, vector<C>, greater<C>> l;
        int ans = INT_MIN;
        int nb = 0; // now budget
        for(int i = 0; i < catId; i++)
        {
            auto &top = pq[i].top();
            //
            nb += top.p;
            //
            l.push(top);
            // cout << top << '\n';
        }
        // puts("-----------------------");

        while(true)
        {
            auto s = l.top(); // smallest of current list
            auto &cat = pq[s.cat]; // same cat as `s`
            // ans = max(ans, l.top().q);
            // if(cat.size() == 1)
                // break;
            cat.pop();
            l.pop();
            auto &catS = pq[s.cat].top(); // smallest of that category

            if(nb - s.p + catS.p > b)
                break;
            else
            {
                nb = nb - s.p + catS.p;
                l.push(catS);
                ans = max(ans, l.top().q);
            }
        }
        printf("%d\n", ans);
    }
}