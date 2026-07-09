#include<fstream>
using namespace std;
int main()
{
	int t,a,b,i;
	ifstream g("euclid2.in");ofstream h("euclid2.out");
	g>>t;
	for(i=1;i<=t;i++)
	{
		g>>a>>b;
		while(a!=b)
		{
			if(a>b)
				a-=b;
			else
				b-=a;
		}
		h<<a;
	}
}
	