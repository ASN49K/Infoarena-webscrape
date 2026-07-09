#include<fstream>
using namespace std;
int d[1025][1025], i, j, n, m, a[1025], b[1025];
fstream f("cmlsc.in", ios::in), g("cmlsc.out", ios::out);
int maxim( int a, int b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	f>>n>>m;
	for(i=1; i<=n; i++)
		f>>a[i];
	for(i=1; i<=m; i++)
		f>>b[i];
	d[0][0]=0;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			if(a[i]==b[j])
				d[i][j]=d[i-1][j-1]+1;
			else
				d[i][j]=maxim(d[i-1][j], d[i][j-1]);
		}
	}
	g<<d[n][m]<<endl;
	int sol[1025];
	int k=0;
	int	i=n,j=m; 
	do{
		if (a[i] == b[j])
		{
			k++;
			sol[k] = b[i];
			i--;
			j--;
		}
		else 
			if (d[i-1][j] < d[i][j-1])
						j--;
					else
						i--;
	}while(i>0 && j>0);	
	for(i=k; i>=1; i--)
		g<<sol[i]<<" ";
	
	
}