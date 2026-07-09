#include "stdio.h"

#define max(a,b) ((a>b)?a:b)

int a[1025];
int b[1025];
int t[1025][1025];
int ut[1025];
int e=0;

int i, j, n, m;

void visszafejt(int x, int y);

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(j=1;j<=m;j++)
		scanf("%d",&b[j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			int s=max(t[i-1][j],t[i][j-1]);
			if(a[i]==b[j])s=max(s,t[i-1][j-1]+1);
			t[i][j]=s;
		}
	printf("%d\n",t[n][m]);
	visszafejt(n,m);
	return 0;
}

void visszafejt(int i, int j)
{
	if(i==0||j==0)return ;
	int ok=0;//ha ok 1 akkor kiir;
	int s=max(t[i-1][j],t[i][j-1]);
	if(t[i-1][j-1]+1>s&&t[i-1][j-1]+1==t[i][j]){ok=1;visszafejt(i-1,j-1);}
	else
	{
		if(t[i-1][j]>=t[i][j-1]) 
			visszafejt(i-1, j ); 
		else 
			visszafejt( i ,j-1);
	}
	
	if(ok)printf("%d ",a[i]);
}