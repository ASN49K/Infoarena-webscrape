#include <stdio.h>
#define NMAX 1123
FILE *fin, *fout;
int n1, n2, v1[NMAX], v2[NMAX], d[NMAX][NMAX], arr[NMAX], pos;
int max(int a, int b)
{
	return (a > b)?a:b;
}
int main()
{
	fin = freopen("cmlsc.in", "r", stdin);
	fout = freopen("cmlsc.out", "w", stdout);
	scanf("%d %d", &n1, &n2);
	for(int i= 1; i<= n1; ++i) scanf("%d", &v1[i]);
	for(int i= 1; i<= n2; ++i) scanf("%d", &v2[i]);
	for(int i = 1; i<= n1; ++i)
	{
		for(int j = 1; j<= n2; ++j)
		{
			if(v1[i] == v2[j])
			{
				d[i][j] = d[i-1][j-1] + 1;
			}
			else
			{
				d[i][j] = max(d[i][j-1], d[i-1][j]);
			}
		}
	}
	printf("%d\n", d[n1][n2]);
	for(int a = n1, b = n2; ;)
	{
		if(d[a][b] == 0) break;
		if(a < 1) break;
		if(d[a][b] == d[a-1][b])
		{
			a--;
			continue;
		}
		if(b < 1) break;
		if(d[a][b] == d[a][b-1])
		{
			b--;
			continue;
		}
		arr[pos] = v1[a];
		a--;
		b--;
		pos++;
	}
	for(int i = pos-1; i>=0; --i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	fclose(fin);
	fclose(fout);
	return 0;
}
