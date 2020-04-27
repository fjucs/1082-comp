#include <bits/stdc++.h>
using namespace std;
using P=pair<int, int>;
#define PB push_back
#define MP make_pair
#define F first
#define S second
vector<P> v;
int T = 1;
int n, m; // num, distance
int msq;
int a, b;
int disq(P a, P b)
{
	return pow(a.first-b.first, 2)+pow(a.second-b.second, 2);
}
int main()
{
	bool fail = false;
	while(cin >> n >> m && (n || m))
	{
		printf("Case %d: ", T++);
		// puts("");
		msq = m*m;
		fail = false;
		v.clear();
		//
		for(int i = 0; i < n && cin >> a >> b; i++)
		{
			if(b > m) fail = true;
			v.PB(MP(a, b));
		}

		if(fail)
		{
			printf("-1\n");
			continue;
		}

		sort(v.begin(), v.end());

		// for(P &p : v)
		// 	printf("%d %d\n", p.F, p.S);

		int ans = 0;
		int c;
		for(int i = 0; i < v.size();)
		{
			if(i == 0)
			{
				c = v[i].F;
				ans++;
			}
			else
			{
				if(disq(v[i], {c, 0}) > msq)
				{
					bool conti = false;
					for(int a = c; a <= v[i].F; a++)
					{
						int pass = 0;
						for(int j = 0; j <= i; j++)
							if(disq(v[j], {a, 0}) <= msq)
								pass++;
						if(pass == i+1)
						{
							// printf(">> (%d %d) (%d %d)\n", v[i-1].F, v[i-1].S, v[i].F, v[i].S);
							// printf(">>> a=%d\n", a);
							c = a;
							conti = true;
							break;
						}
					}
					if(!conti)
					{
						c = v[i].F;
						ans++;
					}
				}
			}
			i++;
		}
		
		printf("%d\n", ans);
	}
}