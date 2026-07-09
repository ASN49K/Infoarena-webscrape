#include <cstdio>

int gcd(int a, int b);

int main()
{
    int n;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        int a, b;

        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a,b));
    }
    return 0;
}

int gcd(int a, int b){
    while (b){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

