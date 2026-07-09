#include<stdio.h>
int main()
{
    
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
 
 long long a,b,aux;
 
 scanf("%lld%lld",&a,&b);
 
     while(b){
         aux=b;
         b=a%b;
         a=aux;}
    
    printf("%lld",a);
    
    return 0;
}
