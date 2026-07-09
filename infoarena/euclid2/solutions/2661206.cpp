#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a,int b)
{
	while(b!=0)
	{
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main()
{
	int m;
	in>>m;
	while(m--)
	{
		int x,y;
		in>>x>>y;
		out<<euclid(x,y)<<"\n";
	}
	return 0;
}
