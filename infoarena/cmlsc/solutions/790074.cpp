#include <stdio.h>
int max[1030][1030];
int a[1030],b[1030];
int m,n;

int maximum(int a,int b){return a>b?a:b;}


int main(){

	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d",&n);scanf("%d",&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j])
			max[i][j]=max[i-1][j-1]+1;
			else
				max[i][j]=maximum(max[i-1][j],max[i][j-1]);
		}
	printf("%d\n",max[n][m]);
	int nr=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(max[i][j]==nr+1)
			{	printf("%d ",a[i]);
				nr++;
			}
	return 0;
}