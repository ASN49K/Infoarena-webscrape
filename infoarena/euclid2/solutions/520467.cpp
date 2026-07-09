#include<fstream>
using namespace std;

int a,b,t;

int cmmdc(int a, int b);

int main ()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for(;t;--t)
	{	f>>a;
		f>>b;
		g<<cmmdc(a,b)<<'\n';
	}
	f.close();
	g.close();
	return 0;
}
int cmmdc(int a, int b)
{
	int r = a % b;
	while (r != 0) 
	{	a = b;
		b = r;
		r = a % b;
	}
	return b;
}