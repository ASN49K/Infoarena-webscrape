#include<cstdio>

int a , b , T;

int gcd ( int a , int b) { 
    if ( b == 0 ) return a; 
    return gcd( b , a % b ) ;
}

int main ()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    
    scanf("%d",&T);
    
    for( ; T-- ; ) {
         scanf("%d %d",&a ,&b);
         printf("%d\n",gcd(a , b ) ) ;
         }

return 0;
}
