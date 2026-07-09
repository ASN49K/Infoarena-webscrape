#include<cstdlib>
#include<string>

long long t,a,b;

long long euclid(long a, long b){
    if(!b)
        return a;
    else
        return euclid(b,a%b);
}

int main(){
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

scanf("%lld",&t);

for(;t;--t)
    {
    scanf("%lld %lld", &a, &b);
    printf("%lld", euclid(a,b));   
    }
return 0;
}
