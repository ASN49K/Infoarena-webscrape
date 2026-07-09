#include <iostream>
#include <fstream>
using namespace std;
long t,i,x,y,rez;

long cmmdc(int a,int b)
{
	long r,cmmdc;
	r=a%b;
	while (b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	cmmdc=a;
	return cmmdc;
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for (i=1;i<=t;i++)
	{
		f>>x>>y;
		g<<cmmdc(x,y)<<endl;
	}
	f.close();
	g.close();
}
