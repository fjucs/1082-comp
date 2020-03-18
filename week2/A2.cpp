#include <bits/stdc++.h>
using namespace std;
using P=pair<int, int>;
using PF=pair<float, float>;
#define PB push_back
#define MP make_pair
#define F first
#define S second
int T=1;
int n, m;
int a, b;
int msq;
vector<P> v;
vector<PF> iv; // invervals
int main()
{
	while(cin >> n >> m && (n || m))
	{
		printf("Case %d: ", T++);
		//
		msq = m * m;
		v.clear();
		iv.clear();
		//
		bool fail = false;
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

		for(P &p : v)
		{
			float d = sqrt(msq - pow(p.S, 2));
			float x = p.F;
			iv.PB(MP(x-d, x+d));
		}

		sort(iv.begin(), iv.end(), [](const PF &lhs, const PF &rhs){
			return lhs.S < rhs.S;
		});

		// for(PF &p : iv)
		// 	printf("%f %f\n", p.F, p.S);

		int ans = 0;
		int r;
		for(int i = 0; i < iv.size(); i++)
		{
			if(i == 0)
			{
				r = iv[i].S;
				ans++;
			}
			else
			{
				if(iv[i].F > r)
				{
					ans++;
					r = iv[i].S;
				}
			}
		}
		printf("%d\n", ans);
	}
}