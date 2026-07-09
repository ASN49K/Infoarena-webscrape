#include <stdio.h>
#include <string.h>


int main()
{
	freopen("cmisc.in", "r", stdin);
	freopen("cmisc.out", "w", stdout);

	short int n, m, a[1025], b[1025], c[1025][1025], i, j, prev[1025][1025];

	scanf("%hd %hd", &n, &m);
	memset(c, 0, sizeof(c));
	
	for(i = 0; i < n; ++i)
	{
		scanf("%hd", &a[i]);
	}
	for(j = 0; j < m; ++j)
	{
		scanf("%hd", &b[j]);
	}

	for(i = n - 1; i >= 0; --i)
	{
		for(j = m - 1; j >= 0; --j)
		{
			if(a[i] == b[j])
			{
				c[i][j] = c[i + 1][j + 1] + 1;
				prev[i][j] = 1;
			}
			if(c[i][j] < c[i][j + 1])
			{
				c[i][j] = c[i][j + 1];
				prev[i][j] = 2;
			}
			if(c[i][j] < c[i + 1][j])
			{
				c[i][j] = c[i + 1][j];
				prev[i][j] = 3;
			}
		}
	}
	printf("%hd\n", c[0][0]);
	int line = 0;
	int col = 0;
	while(line < n && col < m)
	{
		if(a[line] == b[col])
		{
			printf("%hd ", a[line]);
		}
		if(prev[line][col] == 1)
		{
			++line;
			++col;
		}
		if(prev[line][col] == 2)
		{
			++col;
		}
		else
		{
			++line;
		}
	}


	return 0;
}
