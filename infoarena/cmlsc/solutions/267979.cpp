#include <stdio.h>

int s1[100],s2[100],n,m;
int a[100][100];
int lung, comun[100],vechi=0,nr=0;

int max(int a,int b)
{
	if(a<b) return b;
	else return a;
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d %d", &n,&m);
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
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]!=vechi)
			{	comun[nr]=s1[i];
				nr++;
				vechi=a[i][j];
			}
	
	printf("%d\n",lung);
	for(int i=0;i<lung;i++) printf("%d ",comun[i]);
	
	return 0;
}
