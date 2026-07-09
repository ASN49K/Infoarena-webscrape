#include<cstdio>
#define NMAX 1030
using namespace std;

int a[NMAX][NMAX], n, m, v[NMAX], x[NMAX],sol[NMAX];

int main()
{
	freopen("cmlsc.in","r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; ++i)
		scanf("%d", &v[i]);

	for(int i = 1; i <= m; ++i)
		scanf("%d", &x[i]);

	int nr_max = 0;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			if(v[i] == x[j])
				a[i][j] = a[i - 1][j - 1] + 1;
			else
				a[i][j] = (a[i][j - 1] > a[i - 1][j] ? a[i][j - 1] : a[i - 1][j]);
		}
	}

	nr_max = a[n][m];
	int k = 0;
	for(int i = n, j = m; i > 0;)
	{
		if(v[i]== x[j])
		{
			sol[k] = v[i];
			k++;
			i--;
			j--;
		}
		else
		if(a[i][j] == a[i - 1][j])
			i--;
		else
			j--;
	}

	printf("%d\n", nr_max);
	for(int i = nr_max - 1; i >= 0; --i)
		printf("%d ",sol[i]);

	printf("\n");

	return 0;
}
