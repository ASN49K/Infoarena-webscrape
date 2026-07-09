#include<cstdio>
using namespace std;
int cmmdc(int a, int b)
{
    if(a % b == 0) return b;
    else if(b % a == 0) return a;
    return cmmdc(a % b, b % a);
}
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int t, a, b;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }
}
