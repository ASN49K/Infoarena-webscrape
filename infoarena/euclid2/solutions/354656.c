#include<stdio.h>
#define filein "euclid2.in"
#define fileout "euclid2.out"

int t;
int a,b;

int euclid(int a, int b)
	{
	if(!b) return a; //inseamna ca b este cel mai mare divizor comun al numerelor a si b
	return euclid(b,a%b);
	}

int main()
{
freopen(filein,"r",stdin);
freopen(fileout,"w",stdout);
scanf("%d",&t);
while(t--)
	{
	scanf("%d%d",&a,&b);
	printf("%d\n",euclid(a,b));
	}
return 0;
}