#include<stdio.h>
int euclid(int a, int b)
{
	int c;
	while(b){
	c=a%b;
	a=b;
	b=c;}
	return a;
}
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int n,x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",euclid(x,y));
	}
	return 0;
}