#include<stdio.h>

int main()
{
	int n;
	int x,t;
	int s=0;
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		s=0;
		while(n--)
		{
			scanf("%d",&x);
			s^=x;
		}
		if(s)
			printf("DA\n");
		else
			printf("NU\n");
	}
	return 0;
}
