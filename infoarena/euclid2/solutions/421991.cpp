#include <stdio.h>
int main()
{  
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
int a,b,m,T;
scanf("%d",&T);
while(T--)
{
 scanf("%d %d",&a,&b);
 do{ 
    m=a%b; 
    a=b; 
    b=m; 
   } while (m);
    printf("%d\n",a);
}
return 0;
}
