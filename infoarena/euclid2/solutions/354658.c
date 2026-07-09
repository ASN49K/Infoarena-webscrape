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

int gcdb(int a, int b)
{
	if(!a) return b;
	if(!b) return a;
	
	if(!(a&1)&&!(b&1)) return gcdb(a>>1,b>>1)<<1; //daca ambele pare
	if(!(a&1)) return gcdb(a>>1,b); //daca doar a par
	if(!(b&1)) return gcdb(a,b>>1); //daca doar b par
	//inseamna ca ambele sunt impare
	if(a<b) return gcdb(a,(b-a)>>1);
	return gcdb((a-b)>>1,b);
}

int main()
{
freopen(filein,"r",stdin);
freopen(fileout,"w",stdout);
scanf("%d",&t);
while(t--)
	{
	scanf("%d%d",&a,&b);
	printf("%d\n",gcdb(a,b));
	}
return 0;
}