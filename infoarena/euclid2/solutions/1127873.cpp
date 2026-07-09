#include <cstdio>

using namespace std;

inline int gcd(int a, int b){
    if(!b)
        return a;
    return gcd(b, a % b);
}

int main(){
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int n = 0;
    for(scanf("%d", &n); n > 0; --n){
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}
