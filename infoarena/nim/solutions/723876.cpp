#include<cstdio>
using namespace std;
int main()
{
freopen("nim.in","r",stdin);
freopen("nim.out","w",stdout);
int n,t,xorsum,aux;
scanf("%d",&t);
while(t--)
{
 scanf("%d",&n);
 xorsum=0;
 while(n--)
  {
       scanf("%d",&aux);
	   xorsum=xorsum^aux; 
  }
  if(xorsum)
	   printf("DA\n");
	     else printf("Nu\n");
}
return 0;
}
