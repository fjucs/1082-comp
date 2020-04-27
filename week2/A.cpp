#include <bits/stdc++.h>
using namespace std;
using P=pair<int, int>;
using PF=pair<float, float>;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define N 100
int T, n, d;
int pos[N+5], type[N+5]; // pos, type
enum RockType
{
    None = 0,
    Small,
    Big,
};
int main()
{
    int TC=1;
    cin >> T;
	while(T-- && cin >> n >> d)
    {
        memset(pos, 0, sizeof(pos));
        memset(type, 0, sizeof(type));
        //
        char t; // type
        int p;  // pos
        printf("Case %d: ", TC++);
        // input
        getchar();
        for (int i = 1; i <= n && ~scanf("%c-%d", &t, &p); i++)
        {
            getchar();
            type[i] = t == 'B' ? Big : Small;
            pos[i] = p;
        }
        type[0] = type[n+1] = Big;
        pos[0] = 0; pos[n+1] = d;
        n += 2;
        // solve
        int ans = INT_MIN;
        int now[2] = {}; // i-th rock
        bool end_flag = false;
        while (!end_flag)
        {
            for(int f = 0; f < 2; f++) // frog
            {
                int &cur = now[f];
                int next = cur+1;
                if(next >= n) // end
                {
                    end_flag = true;
                    break;
                }
                // find next
                while(!type[next])
                {
                    next++;
                }
                // update ans
                ans = max(ans, pos[next] - pos[cur]);
                //
                cur = next;
                if(type[cur] == Small)
                    type[cur] = None;
            }
        }
        printf("%d\n", ans);
    }
}