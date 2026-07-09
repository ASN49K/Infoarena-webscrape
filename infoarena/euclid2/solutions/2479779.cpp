#include <iostream>
#include<stdio.h>
int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b,a%b);
}
int main() {
    int n, a, b;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i<n; ++i){
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}