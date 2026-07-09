#include <stdio.h>

int cauta (int b, char a[], int m, int *ua)
{
	int i;
	for (i=(*ua)+1; i<m; ++i)
		if (b==(int) a[i]) {*ua=i; return i;}
	return 0;
}

int main()
{
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	int m,n;
	scanf ("%d%d", &m, &n);
	
	char a[1024], aux[1024];

	int b, i;
	for (i=0; i<m; ++i)
		{scanf ("%d", &b);a[i]= b;}
	
	i=0;	int ua=-1;
	scanf ("%d", &b);
	while (i<n && !cauta (b, a, m, &ua))
		{scanf ("%d", &b); i++;}
	
	if (i>=n)
	{
		printf ("%d", 0);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	aux[0]=b;
	int max=0;
	
	while (i<n)
	{
		scanf ("%d", &b);
		if (cauta (b,a, m, &ua))
			aux[++max]=b;
		++i;
	}
	
	fclose(stdin);
	
	printf ("%d\n", max+1);
	for (i=0; i<=max; ++i)
		printf ("%d ", (int) aux[i]);
	fclose(stdout);
	return 0;
}
