#include<bits/stdc++.h>
using namespace std;

ifstream in ("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int x, int y)
{
	if(y==0) return x;
	return cmmdc(y, x % y);
}

int main(){
	int t, a, b;
	for(in >> t; t > 0; t--)
	{
		in >> a >> b;
		out << cmmdc(a, b) << '\n';
	}
	return 0;
}
