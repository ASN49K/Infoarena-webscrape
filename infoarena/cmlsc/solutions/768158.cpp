#include <fstream>
using namespace std;
int n, m, i, j, a[1001], b[1001], dinamica[1001][1001];
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
	for(i=1; i<=n;)
	{
		for(j=1; j<=m;)
		{
			if(a[i]==b[j])
			{
				k++;
				sir[k]=a[i];
				i++;
				j++;
			}
			else if(dinamica[i+1][j] < dinamica[i][j+1])
				j++;
			else
				i++;
		}
	}
	g<<k<<"\n";
	for(i=1; i<=k; i++)
	{
		g<<sir[i]<<" ";
	}
}