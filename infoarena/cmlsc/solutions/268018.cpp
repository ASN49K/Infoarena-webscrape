#include <stdio.h>

int s1[1025],s2[1025],n,m;
short int a[1025][1025];
int lung, comun[1025],nr=0,x,y;

int max(int a,int b)
{
	if(a<b) return b;
	else return a;
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d%d", &n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&s1[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&s2[i]);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s1[i]==s2[j])
				a[i][j]=a[i-1][j-1]+1;
			else
				a[i][j]=max( a[i-1][j], a[i][j-1]);
	lung=a[n][m];
	
	x=n;y=m;
	while(x&&y)
	{
		if(s1[x]==s2[y])
		{	comun[lung-nr-1]=s1[x];
			nr++;
			x--;y--;
		} else
		{
			if(a[x-1][y]<a[x][y-1])
				y--;
			else x--;
		}
	}
	
	printf("%d\n",lung);
	for(int i=0;i<lung;i++) printf("%d ",comun[i]);
	
	return 0;
}
