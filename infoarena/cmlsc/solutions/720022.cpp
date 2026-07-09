#include<stdio.h>
int a[1025],b[1025],t[1025][1025]={0},ut[1025]={0};
int n,m;
int max(int a,int b)
{
	if(a>b)
		return a;
	else 
		return b;
}
void go(int i,int j);
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			int v=max(t[i][j-1],t[i-1][j]);
			if(a[j]==b[i])
				t[i][j]=max(v,t[i-1][j-1]+1);
			else
				t[i][j]=v;
		}
	go(m,n);
	printf("%d\n",t[m][n]);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",t[i][j]);
		printf("\n");
	}
	for(int i=1;i<=t[m][n];i++)
		printf("%d ",ut[i]);
	return 0;
}
void go (int i,int j)
{
	while(t[i][j]==t[i][j-1])
		j--;
	ut[t[i][j]]=a[j];
	if(t[i-1][j-1])
		go(i-1,j-1);
}
