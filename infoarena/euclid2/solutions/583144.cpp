#include<cstdio>
int main()
{
	int n,j,d,i,p,q,r;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d\n",&n);
	for (j=1;j<=n;j++) {
		scanf("%d %d\n",&p,&q);
		if (p>q) d=p; else d=q;
		if (p<q) i=p; else i=q;
		r=d % i;
		while (r!=0)  {
			d=i;
			i=r;
			r=d % i;
		}
		printf("%d\n",i);
	}
	return 0;
}
		