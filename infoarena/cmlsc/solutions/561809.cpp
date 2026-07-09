#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	int max=0,n,m,a=1;
	scanf ("%d %d", &n,&m);
	int ab[n+1][m+1];
		
	for (int i=1;i<=n;i++)
		scanf ("%d", &ab[i][0]);
	for (int i=1;i<=m;i++)
		scanf ("%d", &ab[0][i]);
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			ab[i][j]=0;
	
		
	if (n>=m)
		for (int i=1;i<=m;i++)
			for (int j=a;j<=n;j++)
				if (ab[0][i]==ab[j][0])
				{
					max++;
					a=j+1;
					ab[j][i]=1;
					break;
				}
	if (n<m)	
		for (int i=1;i<=n;i++)
			for (int j=a;j<=m;j++)
				if (ab[i][0]==ab[0][j])
				{
					max++;
					ab[i][j]=1;
					a=j+1;
					break;
				}			
				
	printf ("%d\n", max);
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)	
			if (ab[i][j]==1)
			{
				printf ("%d ", ab[i][0]);
				break;
			}
}	
