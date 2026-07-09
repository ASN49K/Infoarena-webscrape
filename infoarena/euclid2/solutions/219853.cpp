#include <stdio.h>
int a,b,c,t,i,aux;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    for(i=1;i<=t;i++)
     {
       scanf("%d %d",&a,&b);
       if(a<b)
        {
              aux=a;
              a=b;
              b=aux;
        }
       while(b>0)
        {
                 c=a%b;
                 a=b;
                 b=c;
        }
       printf("%d\n",a);
       }
     return 0;
}
                 
    
