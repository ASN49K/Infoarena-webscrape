#include <cstdio>

using namespace std;

inline int cmmdc(long int a,long int b){
    if(b == 0){
        return a;
    }else{
        return cmmdc(b, a%b);
    }
}

int main(){
    long int c,a,b;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%ld",&n);
    for(i = 1;i <= n;++i){
        scanf("%ld %ld",&a,&b);
        c = cmmdc(a, b);
        printf("%ld\n",c);
    }
    return 0;
}
