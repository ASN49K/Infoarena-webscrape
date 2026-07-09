#include <cstdio>

int m, n;
int a[1030], b[1030];
int lcs[1030][1030];
int s[1030], si;

inline int max(int r, int q)
{
	if(r > q)
		return r;
	else
		return q;
}

void read()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
		
	scanf("%d%d", &m, &n);

	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
	}
}

int main()
{
	int i, j;

	read();

	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(a[i] == b[j])
			{
				lcs[i][j] = lcs[i-1][j-1] + 1;
			
			}
			else
			{
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}
	
	i = m;
	j = n;
	
	while(i > 0 && j > 0)
	{
		if(a[i] == b[j])
			s[si++] = a[i], i--, j--;	
		else
			if(lcs[i][j] == lcs[i-1][j])
				i--;
			else
				j--;
	}

        printf("%d ", lcs[m][n]);

	si--;

	while(si >= 0)
	{
		printf("%d ", s[si]);
		si--;
	}

	return 0;
}
