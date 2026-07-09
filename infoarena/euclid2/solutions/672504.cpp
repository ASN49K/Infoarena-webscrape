#include<fstream>
using namespace std;
int cmmdc( int a, int b)
{
	int r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int n,a,b,i;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>a>>b;
		g<<cmmdc(a,b);
		g<<"\n";
	}
	return 0;
}