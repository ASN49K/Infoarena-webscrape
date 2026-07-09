#include<cstdio>
using namespace std;
int main()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	int n,i,j,a,t,s;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		s=0;
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a);
			s=s^a;
		}
		if(s==0)printf("NU\n");
		else printf("DA\n");
	}
	return 0;
}
