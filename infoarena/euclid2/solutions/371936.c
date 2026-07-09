#include <stdio.h>
#include<stdlib.h>

int T, A, B,a,b;

int Euclid(a,b)
{
    if (!b) return a;
    return Euclid(b, a % b);
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d",&T);
    for (;T; --T)
    {
        scanf("%d %d",&A,&B);
        printf("%d\n",Euclid(A, B));
    }        

    return 0;
}

