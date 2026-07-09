#include<stdio.h>

int x[1025],y[1025],a[1025][1025],m,n;

int max(int a,int b)
{
	if(a>b) return a;
	return b;
}

void sir(int lin,int col)
{
	if((lin==0) || (col==0)) return;
	if(x[lin]==y[col])
	{
		sir(lin-1,col-1);
		printf("%d ",x[lin]);
	}
	else
	{
		if(a[lin-1][col]>a[lin][col-1])
			sir(lin-1,col);
		else
			sir(lin,col-1);
	}
}

int main()
{
	int i,j;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&y[i]);
	
	a[0][0]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(x[i]==y[j])
				a[i][j]=1+a[i-1][j-1];
			else
				a[i][j]=max(a[i-1][j],a[i][j-1]);
	
	printf("%d",a[n][m]);
	printf("\n");
	sir(n,m);
}

