#include <cstdio>

using namespace std;

long long cmmdc(long long a,long long b){
    if(!b)
        return a;
    return cmmdc(b,a%b);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int T;
    long long a,b;

    scanf("%d", &T);
    for(int i = 1; i <= T; ++i){
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",cmmdc(a,b));
    }

    return 0;
}
