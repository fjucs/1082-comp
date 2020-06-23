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
double t1, t2, s1, s2;
double width, height;
double area(double w)
{
	double ly = t1 + w, ry = t2 + w;
	double tx = s2 - w, bx = s1 - w;
	//
	bool left = s1 <= ly && ly <= s2;
	bool top = t1 <= tx && tx <= t2;
	bool right = s1 <= ry && ry <= s2;
	bool bottom = t1 <= bx && bx <= t2;
	//
	if(left && right)
		return (s2 - ly + s2 - ry) * width * 0.5;
	if(left && top)
		return (s2 - ly) * (tx - t1) * 0.5;
	if(top && bottom)
		return (bx - t1 + tx - t1) * height * 0.5;
	if(bottom && right)
		return width * height - (t2-bx) * (ry-s1) * 0.5;
	return ly <= s1 ? height * width : 0.0;
}
double w;
int main()
{
	int T=1;
	cin >> kase;
	while(kase-- && cin >> t1 >> t2 >> s1 >> s2 >> w)
	{
		width = t2 - t1;
		height = s2 - s1;
		double dif = area(-w) - area(w);
		printf("Case #%d: %.8lf\n", T++, dif / width / height);
	}
}