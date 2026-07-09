#include<fstream>
using namespace std;
int cmmdc(int a, int b)
{
	while(a!=b)
	{
		if(a>b)
			a-=b;
		else
			b-=a;
	}
}
int main()
{
	int a,b,t;
	ifstream g("euclid2.in");ofstream h("euclid2.out");
	g>>t;
	for(int i=1;i<=t;i++)
	{
		g>>a>>b;
		h<<cmmdc(a,b)<<"\n";
	}
}
	