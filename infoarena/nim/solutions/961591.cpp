#include <cstdio>
using namespace std;
int main()
{
	int t,i,n,c,s,y;
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	scanf("%d",&t);
	for (i=1;i<=t;++i)
	{
		scanf("\n%d\n",&n);
		for (s=0,y=1;y<=n;++y)
		{
			scanf("%d ",&c);
			s^=c;
		}
		if (s)
			printf("DA\n");
		else
			printf("NU\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
