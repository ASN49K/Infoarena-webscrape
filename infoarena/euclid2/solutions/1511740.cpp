#include <cstdio>

using namespace std;
int t,a,b;

int gcd(int x,int y){
    if(!y)return x;
    return gcd(y,x%y);
}

int main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    for(scanf("%d ",&t);t;--t){
        scanf("%d %d ",&a,&b);
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
