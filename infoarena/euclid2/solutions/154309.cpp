#include <stdio.h>

long n,m,T;

int main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    
    scanf("%ld",&T);
    for (;T;T--){
        scanf("%ld %ld",&n,&m);
        while (n!=m)
              if (n>m){n=n%m;if (!n)n=m;}
              else {m=m%n;if (!m)m=n;}
        printf("%ld\n",n);
    }
return 0;
}
