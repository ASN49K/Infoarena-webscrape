#include<cstdio>
int a,r,b;
int main()
{
	freopen("euclid2.in","r",stdin);freopen("euclid2.out","w",stdout);scanf("%d",&a);
	for(;scanf("%d%d",&a,&b)+1;){for(;b;){r=a%b;a=b;b=r;}printf("%d\n",a);}
	return 0;
}
