// uva 10440 AC
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
int n, t, m;
int kase;
vector<int> car;
int tmp;
int main()
{
	cin >> kase;
	while(kase-- && cin >> n >> t >> m)
	{
		car.clear();
		//-
		for(int i = 0; i < m && cin >> tmp; i++)
			car.push_back(tmp);
		//
		int ans = 0;
		if(n > m)
		{
			printf("%d %d\n", car.back() + t, 1);
		}
		else
		{
			if(m % n != 0)
			{
				int r = m % n;
				ans = car[r-1] + 2*t; // 先載走多的車
				// 剩下的跟整除一樣
				for(int i = r + n -1; i < m; i += n) // iterate 每組的最後一台車
				{
					ans = max(ans, car[i]);
					ans += 2*t;
				}
				ans -= t;
				printf("%d %d\n", ans, m/n + 1); // 多一次先載走的
			}
			else
			{
				for(int i = n-1; i < m; i += n) // iterate 每組的最後一台車
				{
					ans = max(ans, car[i]); // 如果每組的最後一台車還沒來要等到他來
					ans += 2 * t;
				}
				ans -= t;
				printf("%d %d\n", ans, m/n);
			}
		}
	}
}