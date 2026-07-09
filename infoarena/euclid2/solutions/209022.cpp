#include <stdio.h>
/*
int main()
{
	int a,b,t;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for (int i=1 ; i<=t ; ++i)
	{
		scanf("%d%d",&a,&b);
		while (a!=b)
			if (a>b) 
				a-=b;
			else
				b-=a;
		printf("%d\n",a);
	}
	return 0;
}
*/

int cmmdc(int x,int y)
{
	int r=x%y;//x%y=restul impartirii lui x la y
	while(r)
	{
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int a,b,t;
	scanf("%d",&t);
	while(t--)//diferit de 0 <=> adevarat ; il verifica pe t daca e nenul si apoi il decrementeaza
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}
