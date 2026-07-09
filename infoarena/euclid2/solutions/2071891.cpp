
#include <stdio.h>
using namespace std;


int cmmdc(int n,int m)
{
    int r;
    while(m)
    {
        r=n%m;
        n=m;
        m=r;
    } return n;
}

int main(void)
{
    int T,A,B;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n",cmmdc(A, B));
    }

    return 0;
}
