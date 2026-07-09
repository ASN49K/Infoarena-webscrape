#include<stdio.h>
int d[1030][1030];
int a[1030],b[1030];
int sol[1030];
inline int max(int a,int b) {return a>b?a:b;}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(j=1;j<=m;j++) scanf("%d",&b[j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			d[i][j]=(a[i]==b[j])?(d[i-1][j-1]+1):(max(d[i-1][j],d[i][j-1]));
	i=n;j=m;
	while(i && j)
		if(a[i]==b[j])
		{
			sol[++sol[0]]=a[i];
			i--;
			j--;
		}
		else
			if(d[i-1][j]<d[i][j-1])
				j--;
			else
				i--;
	printf("%d\n",sol[0]);
	for(i=1;i<=sol[0];i++)
		printf("%d ",sol[sol[0]-i+1]);
	printf("\n");
	return 0;
}
