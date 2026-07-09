#include <cstdio>
using namespace std;

int main()
{
	int t,n,rez,x;
	freopen("nim.in","r", stdin);
	freopen("nim.out","w", stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		rez=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			rez^=x;
		}
		if(rez)
			printf("DA\n");
		else
			printf("NU\n");
	}
	return 0;
}
