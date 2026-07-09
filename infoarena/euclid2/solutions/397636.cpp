#include <stdio.h>
FILE *f=fopen ("euclid2.in", "r");
FILE *g=fopen ("euclid2.out", "w");
long a,b,n,i,k;

int euclid (long a, long b) {
long r=a%b;
while (r)
{
	a=b;
	b=r;
	r=a%b;
}
return b;
}
	

int main() {
fscanf (f, "%ld", &n);
for (i=1;i<=n;i++)
{
	fscanf (f, "%ld%ld", &a, &b);
	k=euclid(a, b);
	fprintf (g, "%ld\n", k);
}
return 0;
}
	