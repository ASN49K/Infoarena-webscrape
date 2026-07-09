#include <stdio.h>

#define NMAX 1030

int a[NMAX], b[NMAX];
int sol[NMAX][NMAX];
int n, m;

inline int MAX(int a, int b) { return (a > b) ? (a) : (b); }


void read()
{
	int i;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; ++i) scanf("%d ", &a[i]);
	for(i = 1; i <= m; ++i) scanf("%d ", &b[i]);
}



int main()
{
	int s[NMAX], h = 0;
	int i, j;
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	read();


	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
		{
			if(a[i] == b[j])
				sol[i][j] = sol[i-1][j-1] + 1;
			else
				sol[i][j] = MAX(sol[i-1][j], sol[i][j-1]);
		}
	printf("%d\n", sol[n][m]);

	i = n;
	j = m;



	while(i && j)
	{
		if(a[i] == b[j])
		{
			s[++h] = a[i];
			--i;
			--j;
		}
		else if(sol[i-1][j] > sol[i][j-1])
			--i;
		else
			--j;
	}
	for(; h; --h) printf("%d ", s[h]);



	return 0;
}

