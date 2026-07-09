#include<stdio.h>
inline int cmd(int a,int b)
{
	if(!b)
		return a;
	return cmd(b,a%b);
}
		
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==b)
		{
			printf("%d\n",a);
			return 0;
	    }
	printf("%d",cmd(a,b));
	return 0;
}