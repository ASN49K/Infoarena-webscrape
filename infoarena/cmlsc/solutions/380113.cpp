#include<stdio.h>
int x[2000],k;
int a[2000],b[2000],i,j,l[2000][2000],m,n;
void solutie(int i,int j)
{
	if(l[i][j]!=0)
	{
		if(a[i]==b[j])
			{solutie (i-1,j-1);
			k++;
			x[k]=a[i];}
			
			else if (l[i-1][j]>=l[i][j-1]) solutie (i-1,j);
			else solutie (i,j-1);
	}
}
int main(void)
{
	//cmlsc
	
	
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%ld %ld",&n,&m);
	for (i=1;i<=n;i++) scanf("%ld",&a[i]);
	for (i=1;i<=m;i++) scanf("%ld",&b[i]);
	for (i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			l[i][j]=0;
		
		for(i=1;i<=n;i++)
{
		for(j=1;j<=m;j++)
			printf("%ld",l[i][j]);
		printf("\n");
}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j]) l[i][j] =l[i-1][j-1]+1;
		else if (l[i-1][j]>l[i][j-1]) l[i][j]=l[i-1][j];
			else l[i][j]=l[i][j-1];
		
for(i=1;i<=n;i++)
{
		for(j=1;j<=m;j++)
			printf("%ld",l[i][j]);
		printf("\n");
}
solutie(n,m);
for(i=1;i<=k;i++)
	printf("%d",x[i]);
return 0;			
}