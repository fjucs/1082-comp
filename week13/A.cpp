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
int kase;
string s;
char *n;
//
struct plussub
{
	stack<LL> num;
	stack<char> op;
	const char *n;
	void calc(string &s)
	{
		n = s.c_str();
		while(*n)
		{
			num.push(readInt());
			if(*n == '+')
			{
				n++;
				printf("%c\n", *n);
				LL tmp = readInt();
				printf("%d + %d\n", num.top(), tmp);
				tmp += num.top();
				num.pop();
				num.push(tmp);
			}
			else if(*n == '*')
			{
				op.push(*n);
				n++;
			}
		}
		while(!num.empty())
		{
			printf("%lld ", num.top());
			num.pop();
		}
		while(!op.empty())
		{
			printf("%c ", op.top());
			op.pop();
		}
		puts("-----------------");
	}
	LL readInt()
	{
		LL ans = 0;
		while(isdigit(*n))
		{
			ans *= 10;
			ans += *n - '0';
			n++;
		}
		printf("ans=%lld\n", ans);
		return ans;
	}
}a;
// struct muldiv
// {
// 	stack<LL> num;
// 	stack<char> op;
// }b;
//
int main()
{
	cin >> kase; getchar();
	while(kase-- && cin >> s)
	{
		a.calc(s);
	}
}