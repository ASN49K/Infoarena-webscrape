#include <cstdio>
using namespace std;
int max(int a, int b)
{
	if (a>b)
		return a;
	return b;
}
int v1[1027],v2[1027],sol[1027],k;
char vaz[257];
int lcs(int i,int j)
{
	if ((!i)||(!j))
		return 0;
	if (v1[i]!=v2[j])
	{
		return max(lcs(i,j-1),lcs(i-1,j));
	}
	if (!vaz[i])
		sol[++k]=i;
	vaz[i]=1;
	return (lcs(i-1,j-1)+1);
}
int main()
{
	int m,n,i;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d\n",&m,&n);
	for (i=1;i<m;++i)
		scanf("%d ",&v1[i]);
	scanf("%d\n",&v1[m]);
	for (i=1;i<n;++i)
		scanf("%d ",&v2[i]);
	scanf("%d",&v2[n]);
	printf("%d\n",lcs(m,n));
	for (i=1026;i;--i)
		if (sol[i])
			printf("%d ",v1[sol[i]]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
