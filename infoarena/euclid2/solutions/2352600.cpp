#include <cstdio>

void swap(long &x,long &y){
    x+=y;
    y=x-y;
    x-=y;
}

long euclid(long x,long y){
    while(y){
        x%=y;
        swap(x,y);
    }
    return x;
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