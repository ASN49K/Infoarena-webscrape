/*
    Keep It Simple!
*/
 
#include<stdio.h>


int main()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);

	int n,m,s,x;
	
	scanf("%d",&n);

	for(int i=1; i<=n; i++)
	{
		scanf("%d",&m);
		s = 0;
		for(int j=1; j<=m; j++)
		{
			scanf("%d",&x);
			s = s^x;
		}
		if( s <= 0 )
			printf("NU\n");
		else
			printf("DA\n");
	}
	return 0;
}