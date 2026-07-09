#include <cstdio>
#define Nmax 1025
using namespace std;

FILE *fi = fopen("cmlsc.in", "r");
FILE *fo = fopen("cmlsc.out", "w");
int v[Nmax];
int w[Nmax];
int a[Nmax][Nmax];
int s[Nmax];
int m;
int n;
int l;
int ii, jj, mx;

void citire()
{
	fscanf(fi, "%d%d", &m, &n);
	for(int i = 1; i <= m; i++)
		fscanf(fi, "%d", &v[i]);
	for(int i = 1; i <= n; i++)
		fscanf(fi, "%d", &w[i]);
}

int max(int a, int b)
{
	if(a > b) return a;
	return b;
}

void cmlsc()
{
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			if(v[i] == w[j])
			{
				a[i][j] = a[i-1][j-1] + 1;
				if (a[i][j] > mx)
				{
					mx = a[i][j];
					ii = i;
					jj = j;
				}
								
			}
			else
				a[i][j] = max(a[i-1][j], a[i][j-1]);
}

void drum()
{
	while(ii)
	{
		if(v[ii] == w[jj])
		{
			s[mx--] = v[ii];
			ii--;
			jj--;
		}
		else if(a[ii-1][jj] > a[ii][jj-1])
			ii--;
		else jj--;
	}
}

int main()
{
	citire();
	cmlsc();
	l = mx;
	drum();
	fprintf(fo, "%d\n", l);
	for(int i = 1; i <= l; i++)
		fprintf(fo, "%d ", s[i]);
	return 0;
}
