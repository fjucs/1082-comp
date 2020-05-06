#include <bits/stdc++.h>
using namespace std;
using P=pair<int, int>;
using PF=pair<float, float>;
#define PB push_back
#define MP make_pair
#define F first
#define S second
unsigned int n, l, r;
// #define BIT(x) (1<<(x))

constexpr uint64_t BIT(uint64_t x)
{
    return 1ULL<<(x);
}

int main()
{
	while(cin >> n >> l >> r)
    {
        uint64_t ans = 0;
        for(int i = 31; i >= 0; i--)
        {
            if(n & BIT(i)) // n&1 m -> 0
            {
                if(ans + BIT(i) <= l)
                    ans += BIT(i);
            }
            else // n&0 m -> 1
            {
                if(ans + BIT(i) <= r)
                    ans += BIT(i);
            }
        }
        printf("%llu\n", ans);
    }
}