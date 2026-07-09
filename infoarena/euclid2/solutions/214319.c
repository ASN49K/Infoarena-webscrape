#include<stdio.h>
#define filein "euclid2.in"
#define fileout "euclid2.out"
using namespace std;
long t;
int a,b;

int euclid(int a, int b)
	{
	if(a==b) return a; //inseamna ca a este cel mai mare divizor comun al numerelor a si b
	if(a>b) return euclid(a%b,b);
	return euclid(a,b%a); //b>a
	}

int main()
{
freopen(filein,"r",stdin);
freopen(fileout,"w",stdout);
scanf("%d",&t);
while(t--)
	{
	scanf("%d %d",&a,&b);
	printf("%d\n",euclid(a,b));
	}
return 0;
}