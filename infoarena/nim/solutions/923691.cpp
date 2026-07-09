#include<stdio.h>
int n,m,s,x;

int main()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);

	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		s=0;
		scanf("%d",&m);
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			s=s^x;
		}
		if(s)
			printf("DA\n");
		else
			printf("NU\n");
	}
}