#include <iostream>
#include <fstream>
using namespace std;
int a[10000],b[10000],n,m;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int cauta(int x)
{
	int i;
	for (i=1;i<=n;i++)
		if (a[i]==x)
			return 1;
	return 0;
}
int main()
{
	int i,z;
	f>>n>>m;
	for (i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
	{
		f>>z;
		if (cauta(z))
			b[i]=z;
		else 
		{
			i--;
			m--;
		}
	}
	g<<m<<endl;
	for (i=1;i<=m;i++)
		g << b[i] <<" ";
	return 0;
}
