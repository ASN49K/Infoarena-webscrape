#include<stdio.h>
#define max(a,b) ((a>b)?a:b)
int N,M,i,j,m,nr,a[1025],b[1025],d[1025],c[1025][1025];
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&N,&M);
	for (i=1;i<=N;i++) scanf("%d",&a[i]);
	for (i=1;i<=M;i++) scanf("%d",&b[i]);
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
			if (a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
				else c[i][j]=max(c[i-1][j],c[i][j-1]);
	m=c[N][M];
	printf("%d\n",m);
	i=N;j=M;nr=0;
	while (m)
	{
		if (a[i]==b[j]){
			d[++nr]=a[i];
			i--;j--;m--;}
		else if (c[i-1][j]>c[i][j-1]) i--;
			else j--;
	}
	for (i=nr;i>=1;i--) printf("%d ",d[i]);
}