#include<cstdio>
using namespace std;
int main()
{
freopen("nim.in","r",stdin);
freopen("nim.out","w",stdout);
int n,t,xorr,aux,i;
scanf("%d",&t);
while(t)
{
 scanf("%d",&n);
 xorr=0;
 for(i=0;i<n;i++)
  {
       scanf("%d",&aux);
	   xorr=xorr^aux; 
  }
  if(xorr)
	   printf("DA\n");
	   else printf("Nu\n");
t--;
}
return 0;
}