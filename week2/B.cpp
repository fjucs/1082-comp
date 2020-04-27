#include <bits/stdc++.h>
using namespace std;
using P=pair<int, int>;
using PF=pair<float, float>;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define N 1000

struct C
{
    int p;
    int q;
};
vector<C> v[N+5];
int catId = 0;
unordered_map<string, int> catM;
void init()
{
    catId = 0;
    catM.clear();
    for(int i = 0; i <= N; i++) v[i].clear();
}
int CAT(const string &s)
{
    if(!catM.count(s))
        catM[s] = catId++;
    return catM[s];
}
int n, b;
// 大於等於 q 的品質的零件是否能組出小於等於 b 元的電腦
bool ok(int q)
{
    int sum = 0;
    for(int i = 0; i < catId; i++)
    {
        int cheap = b+1;
        // 從一個類別中找 品質 >= q 最便宜的
        for(auto &j : v[i])
            if(j.q >= q)
                cheap = min(cheap, j.p);
        // if(cheap == b+1)
        //     return false;
        sum += cheap;
        if(sum > b) // 預算爆炸
            return false;
    }
    return true;
}

int main()
{
	int T; cin >> T;
    while(T-- && cin >> n >> b)
    {
        init();
        //
        int maxq = 0;
        for(int i = 0; i < n; i++)
        {
            string type, name;
            int p, q;
            cin >> type >> name >> p >> q;
            maxq = max(maxq, q);
            v[CAT(type)].PB((C){p, q});
        }
        // 二分答案
        int L = 0, R = maxq;
        while(L < R)
        {
            int mid = L + (R-L+1) / 2;
            if(ok(mid))
                L = mid;
            else
                R = mid-1;
        }
        printf("%d\n", L);
    }
}