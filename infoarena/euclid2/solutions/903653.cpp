#include<iostream>
#include<fstream>
using namespace std;
int cmmdc(int x, int y)
{
	while(x!=y)
	{
		if(x>y)x=x-y;
		else y=y-x;
	}
	return x;
}
int main()
{
	fstream f("euclid2.in", ios::in);
	fstream g("euclid2.out", ios::out);
	int t, a, b, i;
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a;
		f>>b;
		g<<cmmdc(a,b)<<"\n";
	}
	f.close();
	g.close();
	return 0;
}
		