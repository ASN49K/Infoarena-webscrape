#include<stdio.h>
int i,a,b,n,aux;

int main()
{freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
	{scanf("%d%d",&a,&b);
		while(b)
		{aux=a;
		a=b;
		b=aux%b;
		}
	printf("%d\n",a);
	}
}