#include<cstdio>
int a,b,aux,i,n;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		while(a!=b)
		{
			aux=a%b;
			a=b;
			b=aux;
			if(b==0){printf("%d\n",a);
					 a=0;}
		}
	}
}