#include <bits/stdc++.h>
using namespace std;
#define N 5
#define M 10
int n, m;
int num[M+5];
vector<int> v[N+5];
int main()
{
	int T=1;
	while(cin >> n >> m)
	{
		for(int i = 0; i <= N; i++) v[i].clear();
		//
		int sum = 0;
		for(int i = 0; i < m && cin >> num[i]; i++)
			sum += num[i];
		//
		sort(num, num + m);

		int cnt = 0, off = 1;
		for(int i = m-1; i >= 0; i--)
		{
			v[cnt].push_back(num[i]);
			//
			cnt += off;
			if(cnt >= n)
				off = -1, cnt = n-1;
			else if(cnt < 0)
				off = 1, cnt = 0;
		}
		//
		printf("Set #%d\n", T++);
		double avg = (double)sum / (double)n;
		double im = 0.f;
		for(int i = 0; i < n; i++)
		{
			printf(" %d:", i);
			int ss=0;
			for(auto i : v[i])
				ss += i, printf(" %d", i);
			if(ss == 0) putchar(' ');
			puts("");
			im += abs(ss - avg);
		}

		printf("IMBALANCE = %.5lf\n", im);
		puts("");
	}
}