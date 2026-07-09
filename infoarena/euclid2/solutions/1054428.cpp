#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc (int a,int b)
{
	int r;
	while (b!=0)
	{
	r=a%b;
	a=b;
	b=r;
	}
	return a;
}

int main()
{
	int t,a,i,b;
		f>>t;
		for (i=0;i<t;i++)
		{
		f>>a>>b;
		if (a>b)
		g<<cmmdc(a,b);	
		else
		g<<cmmdc(b,a);
		}

	return 0;
}
