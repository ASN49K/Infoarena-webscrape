#include <iostream>
#include <cstdio>
using namespace std;
int cmmdc(int a, int b)
{
    while(b>0)
        {
            int c=a%b;
            a=b;
            b=c;
        }
        return a;
}
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int n, a, b, c, i;
    scanf("%d\n", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d %d\n", &a, &b);
        a=cmmdc(a, b);
        printf("%d\n", a);
    }

    return 0;
}
