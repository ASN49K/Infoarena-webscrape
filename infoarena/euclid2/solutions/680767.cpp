#include<iostream>
#include<fstream>
using namespace std;
int d(int n, int m)
{
	int r;
	do
	{
		r=n%m;
		n=m;
		m=r;
	}while(r!=0);
	return n;
}
int main()
{
	ifstream f("Euclid2.in");
	ofstream g("Euclid2.out");
	long T,a,b,i;
	f>>T;
	for(i=1;i<=T;i++)    
	{
		f>>a>>b;
		g<<d(a,b);
		g<<"\n";
	}
	f.close();
	g.close();
	return 0;
}
