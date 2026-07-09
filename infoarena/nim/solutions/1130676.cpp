/*
    Keep It Simple!
*/

#include<stdio.h>

int n,k,x,s;



int main()
{
   freopen("ssm.in","r",stdin);
   freopen("ssm.out","w",stdout);

   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
     scanf("%d",&k);
     s = 0;
       for(int j=1;j<=k;j++)
         { scanf("%d",&x); s^=x; }
         if( s <= 0)
          printf("NU\n");
         else
          printf("DA\n");
   }
  return 0;
}
