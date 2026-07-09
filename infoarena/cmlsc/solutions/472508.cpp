#include<stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
int m,n,a[1025],b[1025],rec[1025][1025];
void citire()
{scanf("%d%d",&n,&m);
for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
for(int j=1;j<=m;j++)
	scanf("%d",&b[j]);
}
void cmlsc()
{for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		if(a[i]==b[j])
			rec[i][j]=rec[i-1][j-1]+1;
		else
			rec[i][j]=max(rec[i-1][j],rec[i][j-1]);
printf("%d\n",rec[n][m]);
}
void recons(int i,int j)
{if(i<1 || j<1) return;
if(a[i]==b[j])
{recons(i-1,j-1);
printf("%d ",a[i]);
}
else
	if(rec[i][j]==rec[i-1][j])
		recons(i-1,j);
	else
		recons(i,j-1);
}

int main()
{freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
citire();
cmlsc();
recons(n,m);
return 0;
}
