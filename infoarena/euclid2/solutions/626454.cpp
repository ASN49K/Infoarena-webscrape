#include<fstream>
#include<iostream>
using namespace std;
int t;
int cmmdc(int a,int b)
{
	if(b==0)
		return a;
	return cmmdc(b,a%b);
}
int  main()
{
	int a,b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	while(t!=0)
	{
		f>>a>>b;
	g<<cmmdc(a,b);
	if(t>1)
		g<<'\n';
	t--;
	}
	f.close();
	g.close();
	return 0;
}