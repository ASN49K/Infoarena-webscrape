#include<stdio.h>
int t,a,b;
int div(int a, int b)
{
 if(!b) return a;
  return div(b, a % b);
}
int main(void)
 {
   freopen("euclid.in","r",stdin);
   freopen("euclid.out","w",stdout);
   scanf("%d",&t);
   while(t)
    {
        scanf("%d %d",&a,&b); 
        printf("%d\n",div(a,b));
    }
 return 0;
 }