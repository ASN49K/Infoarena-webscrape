#include <cstdio>

using namespace std;

int T,i;
long a,b;

long cmmdc(long a, long b)
{
    long k;
    while (b)
    {
        k=b;
        b=a%b;
        a=k;
    }
    return a;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    for (i=1; i<=T; i++)
    {
        scanf("%ld %ld", &a, &b);
        printf("%ld\n", cmmdc(a,b));
    }

    return 0;
}
