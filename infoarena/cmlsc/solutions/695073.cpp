#include<stdio.h>

long i,j,m,n,scv,a[1200],b[1200],mat[1200][1200],rez[1200];
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%ld %ld",&m,&n);
	for(i=1;i<=m;i++)
		scanf("%ld", &a[i]);
	for(j=1; j<=n; j++)
		scanf("%ld", &b[j]);
	for(i=1; i<=m; i++)
		for(j=1; j<=n; j++)
			if(a[i]== b[j]) mat[i][j]=mat[i-1][j-1]+1;
			else mat[i][j]=(mat[i-1][j]>mat[i][j-1])?mat[i-1][j]:mat[i][j-1];
	i=m; j=n;
	while(i>0&&j>0)
	{
		if(a[i]==b[j]) 
		{
			scv++;
			rez[scv]=a[i];
			i--;
			j--;
		}
		else if(mat[i-1][j]<mat[i][j-1]) j--;
		else i--;
	}
	printf("%ld\n",scv);
	for(i=scv;i>=1;i--) printf("%ld ",rez[i]);
	return 0;
}
