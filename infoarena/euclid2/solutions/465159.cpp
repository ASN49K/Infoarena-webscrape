#include <iostream>
#include <fstream>
using namespace std;

void cmmdc(int &a, int &b)
{
	int r;
	r=a%b;
	a=b;
	b=r;	
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int a,b,t,i;
	f>>t;
	for(i=1; i<=t; i++)
	{
		f>>a>>b;
		while(b!=0)cmmdc(a,b);
		g<<a<<endl;
	}
	f.close();
	g.close();
	return 0;
}
