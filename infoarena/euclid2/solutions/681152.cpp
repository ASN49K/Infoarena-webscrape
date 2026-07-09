#include<iostream>
#include<fstream>
using namespace std;
int d(int a, int b)
{
	int r;
	do
	{
		r=a%b;
		a=b;
		b=r;
	}while(r!=0);
	return a;
}
int main()
{
	ifstream f("Euclid2.in");
	ofstream g("Euclid2.out");
	long t,n,m,i;
	f>>t;
	for(i=1;i<=t;i++)    
	{
		f>>n>>m;
		g<<d(n,m)<<"\n";
	}
	f.close();
	g.close();
	return 0;
}
