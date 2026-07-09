#include<bits/stdc++.h>
using namespace std;

ifstream in ("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int x, int y)
{
	while(y)
	{
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main(){
	int t, a, b;
	for(cin >> t; t > 0; t--)
	{
		in >> a >> b;
		out << cmmdc(a, b) << '\n';
	}
	return 0;
}
