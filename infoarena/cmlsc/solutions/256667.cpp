#include<stdio.h>
#define NMAX 1125

int a[NMAX][NMAX],b[NMAX],c[NMAX],n,m,sol[NMAX],lung=0;;
int maxim(int a,int b)
{
	if(a>b)return a;
		else
		return b;
	
}

int main()
{int i,j,pozi=0,pozj=0,max=0;;
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d%d",&n,&m);
	  for(i=1;i<=n;i++)
		  scanf("%d",&b[i]);
	  for(i=1;i<=m;i++)
		  scanf("%d",&c[i]);
		
	for(i=1;i<=n;i++)	
		for(j=1;j<=m;j++)
			if(b[i]==c[j])
			{
				a[i][j]=1+a[i-1][j-1];
				sol[++lung]=b[i];		
							
			}
			else a[i][j]=maxim(a[i-1][j],a[i][j-1]);
	

	printf("%d\n",a[n][m]);
	for(i=1;i<=lung;i++)
		printf("%d ",sol[i]);
return 0;}
