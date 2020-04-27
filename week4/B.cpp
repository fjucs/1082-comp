#include <bits/stdc++.h>
using namespace std;
#define N 1000
int T, n;
int ty[N+5];
int cnt[N+5];
int main()
{
	cin >> T;
	while(T-- && cin >> n)
	{
		memset(ty, 0, sizeof(ty));
		memset(cnt, 0, sizeof(cnt));
		//
		for(int i = 0; i < n && cin >> ty[i]; i++);
		//
		int ans = 2;
		int sum = ty[0];
		for(int i = 1; i < n-1; i++)
		{
			if(sum + ty[i] < ty[i+1])
			{
				sum += ty[i];
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}