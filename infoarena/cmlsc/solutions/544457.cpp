#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	int m,n,max=0;
	bool last=false;
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
	{
		for (int j=1;j<=n;j++)
			if (ab[i][0]==ab[0][j])
			{
				ab[i][j]=1;
				max++;
				if (j==n)
					last=true;
				break;
			}
		if (last==true)
			break;
	}
	for (int i=0;i<=m;i++)
	{
		for (int j=0;j<=n;j++)
			printf ("%d ", ab[i][j]); 
		printf ("\n");
	}
	printf ("%d \n", max);
	
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			if (ab[i][j]==1)
					printf ("%d ", ab[i][0]);
}	
