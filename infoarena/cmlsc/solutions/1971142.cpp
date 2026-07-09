#include<stdio.h>
#define dim 1025
FILE*f = fopen("cmlsc.in", "r");
FILE*g = fopen("cmlsc.out", "w");

int v[dim], w[dim], d[dim][dim], sol[dim];
int main(){

	int n,m;
	fscanf(f, "%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		fscanf(f, "%d", &v[i]);
	}

	for(int i = 1; i <= m; ++i)
	{
		fscanf(f, "%d", &w[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			if(v[i] == w[j])
			{
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else if(d[i - 1][j] < d[i][j - 1])
			{
				d[i][j] = d[i][j - 1];
			}
			else
			{
				d[i][j] = d[i - 1][j];
			}
		}
	}

	int length = 0;
	for(int i = n, j = m; i && j;)
	{
		if(v[i] == w[j])
		{
			sol[++length] = v[i];
			--i;
			--j;
		}
		else if(d[i - 1][j] < d[i][j - 1])
		{
			--j;
		}
		else
		{
			--i;
		}
	}

	fprintf(g, "%d \n", length);
	for(int i = length; i ; --i)
	{
		fprintf(g, "%d ", sol[i]);
	}

	fclose(f);
	fclose(g);
	return 0;
}
