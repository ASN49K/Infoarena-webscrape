#include<cstdio>
#include<algorithm>
using namespace std;
int n,i,j,k,rez,a;
int main()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&k);
		rez=0;
		for (j=1;j<=k;j++) scanf("%d",&a),rez=rez^a;
		if (rez) printf("DA\n");else printf("NU\n");
	}
	return 0;
}