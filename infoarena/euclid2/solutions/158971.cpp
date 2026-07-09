#include<stdio.h>
int main () {
	long t,i;
	double a,b;
	freopen ("euclid2.in","r",stdin);
	freopen ("euclid2.out","w",stdout);
	scanf ("%ld",&t);
	for (i=1 ; i<=t ; i++)
	{
		scanf ("%lf%lf",&a,&b);
		while (a!=b)
		{
			if (a>b)
				a=a-b;
			else
				b=b-a;
		}
		printf ("%lf",a);
		printf ("\n");
	}
	return 0;
}
