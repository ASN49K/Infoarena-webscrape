#include <cstdio>

int n, a, b;

int euclid(int x, int y)
{
    int r = x%y;
    while(y){
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &n);
    for(; n > 0; n--){
        scanf("%d %d", &a, &b);
        printf("%d\n", euclid(a, b));
    }
    return 0;
}
