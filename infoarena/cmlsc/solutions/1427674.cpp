#include <cstdio>
#include <cstdlib>

using namespace std;

void * aloca_n(int n)
{
	void * vec = NULL;

	vec =  malloc(n);

	if(vec == NULL)
	{
		perror("Eroare : ");
		exit(EXIT_FAILURE);
	}

	return vec;
}

int ** aloca_n_m(int n, int m)
{
	int ** ptr = NULL;

	ptr = (int**) malloc(sizeof(int*) * n);

	if(ptr == NULL)
	{
		perror("Eroare:");
		exit(EXIT_FAILURE);
	}
	for(int i = 0 ; i < n; i ++)
	{
		ptr[i] = (int*) aloca_n(m);
	}

	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			ptr[i][j] = 0;
		}
	}
	return ptr;
}

FILE * open_file(const char * name, const char * opt)
{
	FILE * f = NULL;

	f = fopen(name , opt);

	if(f == NULL)
	{
		perror("Eroare : ");
		exit(EXIT_FAILURE);
	}

	return f;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	FILE *in = 0, *out = 0;
	int * v1 = NULL, *v2 = NULL;
	int n, m, i, j;
	int ** sol = NULL;
	int * sir;
	int len_sol = 0;

	in = open_file("cmlsc.in", "r");
	out = open_file("cmlsc.out", "w");

	fscanf(in, "%d%d", &n, &m);

	v1 = (int*)aloca_n(n + 1);
	v2 = (int*)aloca_n(m + 1);
	sir = (int*) aloca_n(max(n , m) + 1);
	sol = aloca_n_m(n + 1, m + 1);

	for(i = 1; i <= n; ++i)
	{
		fscanf(in , "%d", &v1[i]);
	}

	for(i = 1; i <= m ; ++i)
	{
		fscanf(in , "%d", &v2[i]);
	}

	for(i = 1; i <= n ; ++i)
	{
		for(j = 1; j <= m; ++j)
		{
			if(v1[i] == v2[j])
			{
				sol[i][j] = sol[i - 1][j - 1] + 1;
			}
			else
			{
				sol[i][j] = max(sol[i - 1][j] , sol[i][j - 1]);
			}
		}
	}


	for(i = n, j = m;i != 0 && j != 0;)
	{
		if(v1[i] == v2[j])
		{
			sir[len_sol++] = v1[i];
			--i;
			--j;
		}
		else
		{
			if(sol[i][j - 1] < sol[i - 1][j])
			{
				--i;
			}
			else
			{
				--j;
			}
		}
	}

	fprintf(out, "%d\n", len_sol);
	for(i = len_sol - 1; i >= 0; --i)
	{
		fprintf(out, "%d ", sir[i]);
	}

	free(v1); v1 = NULL;
	free(v2); v2 = NULL;
	free(sir);sir = NULL;

	for(i = 0 ; i < n ; i++)
	{
		free(sol[i]);
		sol[i] = NULL;
	}

	free(sol);
	sol = NULL;
	fclose(in);
	fclose(out);

	return 0;
}
