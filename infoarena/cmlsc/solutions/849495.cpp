#include<stdio.h>

int n,m,v[257], max, i, crt, nr;

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.in", "w", stdout);

	for(i=0; i<n; i++)
	{
		scanf("%d", &crt);
		v[crt]++;
		if(crt>max)
			max=crt;
	}
	for(i=0; i<m; i++)
	{
		scanf("%d", &crt);
		v[crt]++;
		nr += v[crt] > 1 ? 1:0;
		if(crt>max)
			max=crt;
	}
	
	printf("%d\n", nr);
	for(i=0;i<=max; i++)
	{
		if(v[i] > 1)
			printf("%d ",i);
	}	
	return 0;
}