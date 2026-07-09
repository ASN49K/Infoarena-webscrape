#include<stdio.h>
int n;

long long cmmdc(long long a,long long b){
    if(!b) return a;
    else{
        return cmmdc(b,a%b);
    }
}

int main(){
    long long a,b;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d\n",&n);
    while(n--){
        scanf("%lld %lld\n",&a,&b);
        printf("%lld\n",cmmdc(a,b));
    }
    return 0;
}
