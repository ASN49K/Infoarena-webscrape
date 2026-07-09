#include<stdio.h>
using namespace std;
int m, n, a[1050], b[1050], l[1050][1050];

void ceva ()
{
	int i, j;
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
			if (a[i]==b[j])
				l[i][j]=l[i-1][j-1]+1;
			else
				if (l[i-1][j]>=l[i][j-1])
					l[i][j]=l[i-1][j];
				else
					l[i][j]=l[i][j-1];
}

int main()
{
	int i, j, d, sol[1050];
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	scanf ("%d %d", &m, &n);
	for (i=1;i<=m;i++)
		scanf ("%d", &a[i]);
	for (i=1;i<=n;i++)
		scanf ("%d", &b[i]);
	ceva ();
	printf ("%d\n", l[m][n]);
	d=l[m][n];
	i=m;
	j=n;
	while (d>0)
	{
		if (a[i]==b[j])
		{
			sol[d]=a[i];
			i=i-1;
			j=j-1;
			d=d-1;
		}
		else
			if (l[i-1][j]==l[i][j])
				i=i-1;
			else
				j=j-1;
			
	}
	for (i=1;i<=l[m][n];i++)
		printf("%d ", sol[i]);
	printf ("\n");
	
	return 0;

}