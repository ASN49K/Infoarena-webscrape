#include<cstdio>
using namespace std;
int a[1025],b[1025],mat[1025][1025],i,j,m,n,max1,c[1025],val;
int max(int x,int y)
{
	if(x>=y) return x;
	else return y;
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d\n",&n,&m);
	for(i=1;i<n;i++) scanf("%d ",&a[i]);
	scanf("%d\n",&a[n]);
	for(j=1;j<m;j++) scanf("%d ",&b[j]);
	scanf("%d\n",&b[m]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j]) mat[i][j]=mat[i-1][j-1]+1;
			else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
		}
	printf("%d\n",mat[n][m]);
	while(i>=1&&j>=1)
	{
		if (a[i]==b[j])
		{
			val++;
			c[val]=a[i];
			i--;j--;
		}
		else 
			if (mat[i-1][j]<mat[i][j-1]) j--;
		else i--;
	}
	for(i=val;i>1;i--) printf("%d ",c[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}
