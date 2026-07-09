#include<fstream>
#include<iostream>
using namespace std;
int t;
int cmmdc(int a,int b)
{
	if(!b) return a;
	return cmmdc(b,a%b);
}
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int i,a,b;
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<"\n";
	}
	f.close();
	g.close();
}
