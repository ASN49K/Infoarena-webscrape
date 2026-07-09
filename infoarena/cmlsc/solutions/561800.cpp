#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	int max=0,n,m,a=1;
	scanf ("%d %d", &m,&n);
	int ab[m+1][n+1];
		
	for (int i=1;i<=m;i++)
		scanf ("%d", &ab[i][0]);
	for (int i=1;i<=n;i++)
		scanf ("%d", &ab[0][i]);
	
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			ab[i][j]=0;
		
	if (n>=m)
		for (int i=1;i<=m;i++)
			for (int j=a;j<=n;j++)
				if (ab[i][1]==ab[1][j])
				{
					max++;
					a=j;
					ab[i][j]=1;
					break;
				}
	else
		for (int i=1;i<=n;i++)
			for (int j=a;j<=m;j++)
				if (ab[1][i]==ab[j][1])
				{
					max++;
					ab[j][i]=1;
					a=j;
					break;
				}
	printf ("%d\n", max);
	
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)	
			if (ab[i][j]==1)
			{
				printf ("%d ", ab[i][0]);
				break;
			}
}	
