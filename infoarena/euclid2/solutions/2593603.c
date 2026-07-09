#include <stdio.h>
#include <stdlib.h>

int euclid(int a,int b)
{
    int r=a%b;
    if(r==0)
        return b;
    else
        return euclid(b,a%b);
}



int main()
{
    freopen("euclid.in","r",stdin);
    freopen("euclid.out","w",stdout);
    int T;
    scanf("%d",&T);
    int A,B;
    int k=T;
    for (T=0;T<k;T++)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", euclid(A, B));
    }
    return 0;
}
