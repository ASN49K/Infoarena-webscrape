#include<fstream>
#include<algorithm>
#define dim 1026

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[dim],b[dim],n,m;
int sub[dim][dim],sol[dim];

void citire()
{
	int i;
	f>>n>>m;
	for(i = 1;i <= n; i++)
		f>>a[i];
	for(i = 1;i <= m; i++)
		f>>b[i];
}

void dinamic()
{
	int i,j;
	for(i = 1;i <= n; i++)
		for(j = 1;j <= m; j++)
			if(a[i] == b[j])
				sub[i][j] = sub[i-1][j-1] + 1;
			else
				sub[i][j] = max(sub[i-1][j],sub[i][j-1]);
			
}

void afisare()
{
	int i,j,nr=0;
	g<<sub[n][m]<<"\n";
	/*for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= m; j++)
			g<<sub[i][j]<<" ";
		g<<"\n";
	}*/
	i = n;
	j = m;
	while(i != 0 && j != 0)
	{
		if(a[i] == b[j])
		{
			nr++;
			sol[nr] = a[i];
			i--;
			j--;
		}
		else
			if(sub[i][j] == sub[i-1][j-1])
				i--;
			else
				j--;
	}
	
	for(i = nr;i >= 1; i--)
		g<<sol[i]<<" ";
	
}

int main()
{
	citire();
	dinamic();
	afisare();
	return 0;
}
