#include<fstream>
#define dim 258
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[dim],b[dim],n,m;
int sir[dim][dim];
int sol[dim];

void citire()
{
	int i;
	f>>n>>m;
	for(i = 1 ; i <= n; i++)
		f>>a[i];
	for(i = 1; i <= m; i++)
		f>>b[i];
}

void calculeaza()
{
	int i,j;
	for( i = 1;i <= n; i++)
		for(j = 1;j <= m; j++)
		{
			if(a[i] == b[j])
				sir[i][j]=sir[i-1][j-1] + 1;
			else
				if(sir[i-1][j] < sir[i][j-1])
					sir[i][j]=sir[i][j-1];
				else
					sir[i][j]=sir[i-1][j];
		}
		/*
		for( i = 1;i <= n; i++)
		{
			for( j = 1;j <= m; j++)
				g<<sir[i][j]<<" ";
			g<<"\n";
		}
		*/
}

void afisare()
{
	int nr,i;
	nr=0;
	g<<sir[n][m]<<"\n";
	while( n !=0 && m !=0 )
	{
		if( a[n] == b[m] )
		{
			sol[nr]=a[n];
			nr++;
			n--;
			m--;
		}
		else
			if(sir[n][m] == sir[n-1][m])
				n--;
			else
				m--;
	}
	
	for(i = nr-1; i >= 0 ; i--)
		g<<sol[i]<<" ";
	
}


int main()
{
	citire();
	calculeaza();
	afisare();
	return 0;
}

