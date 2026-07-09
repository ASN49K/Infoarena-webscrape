#include <stdio.h>
int gcd(int a, int b){
    if (!b) return a;
    else return gcd(b, a%b);
}
int main()
{
    int a,b,n,i;
    freopen("euclid2.in", "r",stdin);
    scanf("%d\n", &n);
    freopen("euclid2.out","w",stdout);

    for (i=0;i<n;i++){
        scanf("%d %d\n", &a,&b);
        printf("%d\n", gcd(a,b));
    }
    return 0;
}
