#include <iostream>
#include <cstdio>
#include <vector>
#define mod 9973
#define N 1000005

using namespace std;

long long a, b;
int n;

long long cmmdc(long long a, long long b)
{
    if(b==0)
        return a;
    return cmmdc(b, a%b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d\n", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld\n", &a, &b);
        printf("%lld\n", cmmdc(a, b));
    }
    return 0;
}
