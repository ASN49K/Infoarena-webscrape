#include <iostream>
#include <cstdio>
using namespace std;
int cmmdc(int x, int y)
{
    int aux,r;
    if(x<y)
    {
        aux=x;
        x=y;
        y=aux;
    }
    while(y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    int n, a, b, c;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d\n", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d\n", &a, &b);
        c=cmmdc(a,b);
        printf("%d\n", c);
    }
    return 0;
}
