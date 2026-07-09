#include <cstdio>
#define max(a,b) (b<a)?a:b

int mat[1025][1025];
int a[1025],b[1025],v[1025];
int main()
{
	int i,n,m,j;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if (a[i]==b[j])
				mat[i][j]=mat[i-1][j-1]+1;	
			else 
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
		}
	--j;--i;
	printf("%d\n",mat[i][j]);
	while (i&&j&&mat[i][j]!=0)
	{
		while (mat[i][j]==mat[i-1][j]) --i;
		while (mat[i][j]==mat[i][j-1]) --j;
		v[++v[0]]=a[i];
		--i;--j;
	}
	for(i=v[0];i>0;i--) printf("%d ",v[i]);
}
