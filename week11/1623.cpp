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
#define N 1000000
int f[N+5]; // forecast in day i
int kase;
int n, m;      // num of lake, forecast in m days
set<int> s;    // unused norain day
vector<int> v; // rain days
int main()
{
	cin >> kase;
	while(kase-- && cin >> n >> m)
	{
		for(int i = 0; i < m && cin >> f[i]; i++);
		//

	}
}