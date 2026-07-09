using namespace std;
#include<stdio.h>
int n,i,a,b,aux;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		while(a!=0)
		{
			if(a<b)
			{
				aux=a;
				a=b;
				b=aux;
			}
			a=a-b;
		}
		printf("%d\n",b);
	}
	return 0;
}