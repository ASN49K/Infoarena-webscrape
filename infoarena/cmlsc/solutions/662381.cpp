#include<fstream>
#define dim 1025
#define dim2 257
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,i,j,k,nr=0;
int c[dim];
int a[dim],b[dim];
int elcom;
int elcom2,pozelcom2a,pozelcom2b;
int pozelcoma,pozelcomb;
int main()
{
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	j=1;
	while(j<=m)
	{
		for(i=1;i<=n;i++)
			if(a[i]==b[j])
			{
				elcom=a[i];
				pozelcoma=i;
				pozelcomb=j;
				j=m+1;
				i=n+1;
			}
		j++;
	}
	j=m;
	while(j>=1)
	{
		for(i=n;i>=1;i--)
			if(a[i]==b[j])
			{
				elcom2=a[i];
				pozelcom2a=i;
				pozelcom2b=j;
				j=0;
				i=0;
			}
		j--;
	}
	/*g<<elcom<<" "<<pozelcoma<<" "<<pozelcomb;
	g<<"\n";
	g<<elcom2<<" "<<pozelcom2a<<" "<<pozelcom2b;*/
	for(i=pozelcoma;i<=pozelcom2a;i++)
		c[a[i]]++;
	for(i=pozelcomb;i<=pozelcom2b;i++)
		c[b[i]]++;
	for(i=1;i<=dim2;i++)
		if(c[i]==2)
			nr++;
	g<<nr;
	g<<"\n";
	for(i=1;i<=dim2;i++)
		if(c[i]>1)
			g<<i<<" ";
	return 0;
}
