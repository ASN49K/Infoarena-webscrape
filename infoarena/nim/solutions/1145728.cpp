/*
    Keep It Simple!
*/

#include<stdio.h>

int T,N,S,x;

int main()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);

	scanf("%d",&T);
	while(T--)
	{
		S=0;
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&x);
			S^=x;
		}

		if( S == 0 ) printf("NU");
		else printf("DA");
	}
}
