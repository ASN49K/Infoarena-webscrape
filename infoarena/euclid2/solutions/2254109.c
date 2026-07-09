#include <stdio.h>

int gcd(int a, int b){

    int r;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void)
{
    freopen("euclid.in", "r", stdin);
    freopen("euclid.out", "w", stdout);

    int a, b, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}
