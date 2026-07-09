#include <stdio.h>
#include <stdlib.h>
int T, A, B;
int euclid(int a, int b)
{
    int r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", euclid(A, B));
    }
    return 0;
}
