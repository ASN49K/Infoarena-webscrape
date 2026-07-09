#include<cstdio>
int a,b,aux;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d%d",&a,&b);
	while(a!=b)
	{
		if(a<b){aux=a;
				a=b;
				b=aux;}
		a/=b;
	}
	printf("%d",a);
}