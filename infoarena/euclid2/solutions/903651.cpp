#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream f("euclid2.in", ios::in);
	fstream g("euclid2.out", ios::out);
	int t, a, b, cmmdc, i;
	f>>t;
	for(i=1;i<=t;i=i+2)
	{
		f>>a;
		f>>b;
		while(a!=b)
		{
			if(a>b)a=a-b;
			else b=b-a;
		}
		g<<a<<"\n";
	}
	f.close();
	g.close();
}
		