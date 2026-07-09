#include<iostream>
#include<fstream>
using namespace std;
int E(int a,int b)
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
	int t,a,b,i;
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		g<<E(a,b)<<"\n";
	}
	f.close();
	g.close();
	return 0;
}
