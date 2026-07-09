#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	int m,n,max=0;
	scanf ("%d %d", &m,&n);
	int ab[m+1][n+1];
	for (int i=1;i<=m;i++)
		scanf ("%d", &ab[i][0]);
	for (int i=1;i<=n;i++)
		scanf ("%d", &ab[0][i]);
	
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			ab[i][j]=0;
		
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			if (ab[i][0]==ab[0][j])
			{
				if (i!=1 && j!=1)
					ab[i][j]=ab[i-1][j-1]+1;
				else
					ab[i][j]=1;
				if (ab[i][j]>max)
					max=ab[i][j];
			}
	
	printf ("%d \n", max);
	
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			if (ab[i][j]==max)
				for (int t=max-1;t>=0;t--)
					printf ("%d ", ab[i-t][0]);
}	
