#include <cstdio>
static inline int gcd(int u, int v){
    if(u == v)
        return v;
    if(0==u)
        return v;
    if(0==v)
        return u;
    if(0==(u&1)){
        if(0==(v&1))
            return (gcd((u>>1), (v>>1))<<1);
        else
            return  gcd(u>>1, v);
    }
    else if(0==(v&1))
        return gcd(u, (v>>1));
    else{
        if(u>=v)
            return gcd(((u-v)>>1), v);
        else
            return gcd(((v-u)>>1), u);
    }
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int t,a,b;
    for(scanf("%d",&t);t;--t) {
        scanf("%d %d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
}
