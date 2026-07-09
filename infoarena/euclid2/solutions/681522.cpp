#include<iostream>
#include<fstream>
using namespace std;

int cmmdc(long a,long b)
{
	int r;
	do
	{
		r=a%b;
		a=b;
		b=r;
	}
	while(r!=0);
	return a;
}
int main()
{
	ifstream f("euclid.in");
	ofstream g("euclid.out");
	long n,x,y,i;
	f>>n;
	for(i=0;i<n;i++)
	{
		f>>x>>y;
		g<<cmmdc(x,y);
		g<<"\n";
	}
	f.close();
	g.close();
	return 0;
}

	