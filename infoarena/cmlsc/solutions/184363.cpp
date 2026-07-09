#include<stdio.h>

long x[110],y[110],lcs[110][110],k,h,n,m,i,d[110];
int main()
{	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%ld%ld",&m,&n);
	for(k=1;k<=m;k++)
		scanf("%ld",&x[k]);
	for(k=1;k<=n;k++)
		scanf("%ld",&y[k]);
	for(k=1;k<=m;k++)
		for(h=1;h<=n;h++)
			if(x[k]==y[h])
				lcs[k][h]=1+lcs[k-1][h-1];
			else	if(lcs[k-1][h]>lcs[k][h-1]) lcs[k][h]=lcs[k-1][h];
				else	lcs[k][h]=lcs[k][h-1];
	printf("%ld\n",lcs[m][n]);
	for(i=0,k=m,h=n;lcs[k][h];)
		if(x[k]==y[h]){d[i++]=x[k];k--;h--;}
		else	if(lcs[k][h]==lcs[k-1][h]) k--;
			else h--;
	for(k=i-1;k>=0;k--) printf("%ld ",d[k]);
	return 0;
}