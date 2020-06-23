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
//
struct Solver
{
	stack<LL> num;
	stack<char> op;
	const char *n;
	enum State
	{
		A, // read int
		B  // read op
	}state;
	void init()
	{
		state = A;
		while(!num.empty()) num.pop();
		while(!op.empty()) op.pop();
	}
	using calcFunc = std::function<LL(LL, LL)>;
	LL calc(string &s, char fir, char sec, calcFunc firstCalc, calcFunc secondCalc)
	{
		n = s.c_str();
		while(*n)
			switch(state)
			{
			case A:
				num.push(readInt());
				state = B;
			break;
			case B:
				if(*n == fir)
				{
					n++;
					LL tmp = readInt();
					tmp = firstCalc(tmp, num.top());
					num.pop();
					num.push(tmp);
					state = B;
				}
				else if(*n == sec)
				{
					op.push(*n);
					n++;
					state = A;
				}
			break;
		}
		// calc
		while(!op.empty())
		{
			LL a = num.top();
			num.pop();
			LL b = num.top();
			num.pop();
			LL ans = secondCalc(a, b);
			num.push(ans);
			op.pop();
		}
		return num.top();
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
		return ans;
	}
}solver;
//
LL add(LL a, LL b)
{
	return a+b;
}
LL mul(LL a, LL b)
{
	return a*b;
}
int main()
{
	cin >> kase; getchar();
	while(kase-- && cin >> s)
	{
		solver.init();
		LL ans = solver.calc(s, '+', '*', add, mul);
		printf("The maximum and minimum are %lld and ", ans);
		solver.init();
		ans = solver.calc(s, '*', '+', mul, add);
		printf("%lld.\n", ans);
	}
}