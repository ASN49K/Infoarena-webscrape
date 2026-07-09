#include <iostream>
#include <fstream>
using namespace std;
long t,i,x,y,rez;

int cmmdc(int a,int b)
{
	long r;
	r=a%b;
	while (r!=0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for (i=1;i<=t;i++)
	{
		f>>x>>y;
		if (x>y)
			rez=cmmdc(x,y);
		else rez=cmmdc(y,x);
		g<<rez;
	}
	f.close();
	g.close();
}
