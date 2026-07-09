#include<stdio.h>

inline int gcd(int a, int b){
    if(! b)
        return a;
    return gcd(b, a % b);
}

int main(){
    int n, A, B;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }
    return 0;
}
