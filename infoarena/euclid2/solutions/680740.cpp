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
	long T,a,b,i;
	f>>T;
	for(i=1;i<=T;i++)    
	{
		f>>a>>b;
		g<<d(a,b)<<"\n";
	}
	f.close();
	g.close();
	return 0;
}
