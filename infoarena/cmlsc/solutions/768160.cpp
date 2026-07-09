#include <fstream>
using namespace std;
int n, m, i, j, a[1025], b[1025], dinamica[1025][1025];
int main()
{
	
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>n>>m;
	for(i=1; i<=n; i++)
	{
		f>>a[i];
	}
	for(j=1; j<=m; j++)
	{
		f>>b[j];
	}
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			if(a[i]==b[j])
				dinamica[i][j]=1+dinamica[i-1][j-1];
			else
				dinamica[i][j]=max(dinamica[i-1][j], dinamica[i][j-1]);
		}
	}
	int k=0, sir[1400];
	for(i=n, j=m; j;)
	{
		if(a[i]==b[j])
		{
			k++; 
			sir[k]=a[i];
			i--; 
			j--;
		}
		else if(dinamica[i-1][j]<dinamica[i][j-1])
			j--;
		else
			i--;
	}
	g<<k<<"\n";
	for(i=k; i>=1; i--)
	{
		g<<sir[i]<<" ";
	}
}