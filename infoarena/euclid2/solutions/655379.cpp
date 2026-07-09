#include<fstream>
using namespace std;

unsigned int  i,a,b,t;
int cmmdc(int a, int b)
{
	int r;
	r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	while(t)
	{
		--t;
		f>>a>>b;
		g<<cmmdc(a,b)<<"\n";
	}
	return 0;
}
		