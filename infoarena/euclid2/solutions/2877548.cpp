#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
#define cin f
#define cout g
void solve()
{
	int x, y;
	cin >> x >> y;
	while(y)
	{
		int r = x % y;
		x = y;
		y = r;
	}
	cout<<x<<'\n';
}
int main()
{
	int t; cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}