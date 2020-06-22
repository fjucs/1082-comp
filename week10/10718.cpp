#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using P=pair<int, int>;
using PF=pair<float, float>;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define BIT(x) (1U<<(x))
unsigned int n, l, u;
int main()
{
	while(cin >> n >> l >> u)
    {
        unsigned int ans = 0;
        for(int i = 31; i >= 0; i--)
        {
            if(n & BIT(i)) // n == 1
            {
                if((ans | BIT(i)) <= l)
                    ans |= BIT(i);
            }
            else // n == 0
            {
                if((ans | BIT(i)) <= u)
                    ans |= BIT(i);
            }
        }
        printf("%u\n", ans);
    }
}