#include<stdio.h>
int main()
{
 int i,a,b,r,T;
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
  scanf("%d",&T);
  for(i=1;i<=T;i++)
  {
     scanf("%d %d",&a,&b);
      do
      {
	     r=a%b;
	     a=b;
	     b=r;
      }while(r!=0);

    printf("%d\n",a);
   }
   return 0;
}
