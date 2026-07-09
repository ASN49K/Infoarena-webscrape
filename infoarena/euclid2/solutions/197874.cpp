#include <stdio.h>

int main()
{
	int a,b;
	freopen ("cmmdc.in", "r", stdin);
	scanf ("%d", &a);
	scanf ("%d", &b);
	fclose(stdin);
	
	while (b)
	{
		int r=a%b;
		a=b;
		b=r;
	}
	
	if (a==1) a=0;
	freopen("cmmdc.out", "w", stdout);
	printf ("%d", a);
	fclose(stdout);
	return 0;
}
