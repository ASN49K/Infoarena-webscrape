#include<stdio.h>
using namespace std;
int d[1025][1025],a[1025],b[1025],n,m;
void afis(int i, int j)
{
	if(!d[i][j])
		return;
	if(a[i]==b[j]){
		afis(i-1,j-1);
		printf("%d ",a[i]);
		return;
	}
	if(d[i-1][j]==d[i][j]){
		afis(i-1,j);
		return;
	}
	afis(i,j-1);
}
int main()
{
	int i,j;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(i=1;i<=m;++i)
		scanf("%d",&b[i]);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(a[i]==b[j])
				d[i][j]=d[i-1][j-1]+1;
			else
				d[i][j]=(d[i-1][j]>d[i][j-1])?d[i-1][j]:d[i][j-1];
	printf("%d\n",d[n][m]);
	afis(n,m);
	fcloseall();
	return 0;
}