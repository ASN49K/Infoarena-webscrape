#include <stdio.h>

int T,i,r,a,b;

int main ()
{
    freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);
    
    scanf ("%d",&T);
    
    for (i=1;i<=T;i++){
        scanf ("%d %d",&a,&b);
        r=1;
        
        while (r!=0){
              r=a%b;
              a=b;
              b=r;
              }
              
        printf ("%d\n",a);
        
        }
        
    return 0;
}
