#include <bits/stdc++.h>
using namespace std;
using LL=long long;
unordered_map<int, bool> mm;
int T;
int n, k;
int getDi(LL in)
{
	int l = 0;
	while(in)
	{
		in /= 10;
		l++;
	}
	return l;
}
int main()
{
	cin >> T;
	while(T-- && cin >> n >> k)
	{
		mm.clear();
		mm[k] = true;
		LL maxN = k;
		LL tmp = k;
		while(true)
		{
			tmp *= tmp;
			int nowDi = getDi(tmp), div = nowDi - n;
			// printf(">> nowDi=%d div=%d tmp=%d\n", nowDi, div, tmp);
			for(int i = 0; i < div; i++)
				tmp /= 10;
			// printf("After=%d\n", tmp);
			maxN = max(maxN, tmp);
			// printf("> %d\n", tmp);
			if(!mm.count(tmp))
				mm[tmp] = true;
			else
				break;
		}
		printf("%lld\n", maxN);
	}
}