#include<stdio.h>
int t,x,y,aux;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&x,&y);
		if(x<y)
		{
			aux=x;
			x=y;
			y=aux;
		}
		while(y)
		{
			aux=x;
			x=y;
			y=aux%y;
		}
		printf("%d\n",x);
	}
	return 0;
	
}
