#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int xorsum,i,j,n,k,a;

int main()
{
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>k;
		xorsum=0;
		for(j=1;j<=k;j++)
		{
			f>>a;
			xorsum^=a;
		}
		if(xorsum)g<<"DA\n";
		else g<<"NU\n";
	}
	return 0;
}
