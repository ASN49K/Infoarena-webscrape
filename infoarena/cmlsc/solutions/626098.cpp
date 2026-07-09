#include <cstdio>
#include <vector.h>

int main()
{
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	int m,n, anz=0;
	vector <int> zahlen;
	scanf ("%d %d", &m, &n);
	
	int a[m], b[n], ab[m+1][n+1], max = 0;
	for (int i = 0; i < m; i++)
	{
		scanf ("%d", &a[i]);
		ab[i][0] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", &b[i]);
		ab[0][i] = 0;
	}
	ab[m][0] = 0;
	ab[0][n] = 0;
	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (a[i-1] == b[j-1])
			{
				ab[i][j] = ab[i-1][j-1] + 1;
				if (ab[i][j] > max)
				{
					max = ab[i][j];
					zahlen.push_back(a[i-1]);
				}
			}
			else 
				ab[i][j] = max;
	
	printf ("%d\n", max);
	for (int i = 0; i < zahlen.size(); i++)
		printf ("%d ", zahlen[i]);
}