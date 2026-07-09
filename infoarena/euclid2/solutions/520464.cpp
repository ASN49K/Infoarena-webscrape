#include<iostream>
#include<fstream>
using namespace std;

int cmmdc(int a, int b);

int main ()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int a,b,t;
	f>>t;
	for(;t;--t)
	{	f>>a;
		f>>b;
		g<<cmmdc(a,b)<<endl;
	}
	f.close();
	g.close();
	return 0;
}
int cmmdc(int a, int b)
{
	if(b==0) return a;
	else return cmmdc(b,a%b);
}
