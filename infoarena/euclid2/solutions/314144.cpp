#include<stdio.h>
int n,x,y;

int ec(int a, int b)
	{
		if(!b)return a;
		return ec(b,a%b);
}

int main()
	{
		freopen("euclid2.in","r",stdin);
		freopen("euclid2.out","w",stdout);
		scanf("%d",&n);
		for(;n>0;--n)
		{
			scanf("%d%d",&x,&y);
		printf("%d\n",ec(x,y));
		}
		
}