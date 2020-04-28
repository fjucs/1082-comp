#include <bits/stdc++.h>
using namespace std;
using P=pair<int, int>;
using PF=pair<float, float>;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define N 100000
int n, w[N+5]; // number, rw[i]=award of i
int Left[N+5], Right[N+5]; // take from Left or Right of i
// n=odd, p 個禮物能不能滿足?
bool ok(int p)
{
    int l = w[1], r = p - l; // total of l or r
    Left[1] = l, Right[1] = 0;
    // printf("> %d %d\n", l, r);
    for(int i = 2; i <= n; i++)
    {
        if(i % 2 != 0) // odd
        {
            Right[i] = min(r-Right[i-1], w[i]);
            Left[i] = w[i] - Right[i];
        }
        else // even
        {
            Left[i] = min(l-Left[i-1], w[i]);
            Right[i] = w[i] - Left[i];
        }
    }

    return Left[n] == 0;
}

int main()
{
	while(cin >> n && n)
    {
        for(int i = 1; i <= n && cin >> w[i]; i++);
        w[n+1] = w[1];
        //
        if(n == 1)
        {
            printf("%d\n", w[1]);
            continue;
        }

        int L = 0, R = N;
        for(int i = 1; i <= n; i++)
        {
            L = max(L, w[i]+w[i+1]);
            // R = max(R, w[i]*3);
        }
        // Odd
        if(n % 2 != 0)
        {
            while(L < R)
            {
                int mid = (L+R) / 2;
                // printf("L=%d R=%d M=%d\n", L, R, mid);
                if(ok(mid))
                    R = mid;
                else
                    L = mid + 1;
            }
        }
        printf("%d\n", L);
    }
}