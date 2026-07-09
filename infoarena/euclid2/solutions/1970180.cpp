#include <cstdio>

int n, a, b, i, r;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &n);
    for (i=1; i<=n; i++){
        scanf("%d%d", &a, &b);
        while(b){
            r=a%b;
            a=b; b=r;
        }
        printf("%d\n", a);
    }
    return 0;
}
