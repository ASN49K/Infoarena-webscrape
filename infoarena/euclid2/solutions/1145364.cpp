/*
    Keep It Simple!
*/

#include<stdio.h>

int x,y,T;

int euclid(int a,int b)
{
	if(!b)
	     return a;
    return euclid(b,a%b);
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",euclid(x,y));
	}
}
