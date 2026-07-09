#include<fstream>
using namespace std;
int t,x,y,i;
int cmmdc(int a, int b )
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
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>x>>y;
		g<<cmmdc(x,y)<<"\n";
	}
	return 0;
}

