#include<iostream>
#include<fstream>
using namespace std;
int euclid(int a,int b)
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
	int T,a,b,i;
	f>>T;
	for(i=1;i<=T;i++)
	{
		f>>a>>b;
		g<<euclid(a,b)<<"\n";
	}
	f.close();
	g.close();
	return 0;
}
