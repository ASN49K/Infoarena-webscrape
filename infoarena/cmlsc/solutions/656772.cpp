#include<cstdio>
using namespace std;
int a[1025],b[1025],c[1025],i,j,m,n,nr;
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
			if(a[i]==b[j])
			{
				nr++;
				c[nr]=a[i];
			}
		} 
	printf("%d\n",nr);
	for(i=1;i<=nr;i++) printf("%d ",c[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}
