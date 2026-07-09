#include <cstdio>

long euclid(long x,long y){
    if(!y) return x;
    return euclid(y,x%y);
    return (!y ? x:euclid(y,x%y));
}

int main() {
    freopen("euclid.in","r",stdin);
    freopen("euclid.out","w",stdout);

    long t;
    scanf("%ld",&t);
    for(long i=0;i<t;++i){
        long x,y;
        scanf("%ld %ld",&x,&y);
        printf("%ld\n",euclid(x,y));
    }
    return 0;
}