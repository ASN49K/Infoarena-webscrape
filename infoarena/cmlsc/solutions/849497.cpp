#include<stdio.h>

int n,m,v[257], min, i, crt, nr;
int a[1024], b[1024];

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for(i=0; i<n; i++)
	{
		scanf("%d", &crt);
		v[crt]++;
		a[i] = crt;
	}
	for(i=0; i<m; i++)
	{
		scanf("%d", &crt);
		v[crt]++;
		nr += v[crt] > 1 ? 1:0;
		b[i] = crt;
	}
	
	printf("%d\n", nr);
	for(i=0;i<n; i++)
	{
		if(v[a[i]] > 1)
			printf("%d ",a[i]);
	}	
	return 0;
}