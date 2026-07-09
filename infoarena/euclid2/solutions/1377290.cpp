#include <cstdio>

using namespace std;

int gcd(int a, int b){
    if(!b)
        return a;
    return gcd(b, a % b);
}

int main(){
    int T, a, b;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &T);
    while(T){
        --T;
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}
