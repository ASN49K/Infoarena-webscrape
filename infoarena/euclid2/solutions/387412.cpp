#include<stdio.h>

int main()
{
long test,aux,a,b;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);	
scanf("%ld",&test);	
test=test+1;
while(--test)
	{
		scanf("%ld%ld",&a,&b);
		if (a<b)
		{
			aux=b;
			b=a;
			a=aux;
		}
		while(b)
		{
			aux=(a%b);
			a=b;
			b=aux;
		}
		printf("%ld\n",a);	
	}

return 0;
}
