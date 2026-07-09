#include <cstdio>
using namespace std;

int euclid (int a, int b)
{
    while(b!=0)
    {
    int r=a%b;
    a=b;
    b=r;
    }
    return a;
}
int main()
{
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);
    int n;
    scanf("%d\n", &n);
    for (int i=1; i<=n; i++)
    {
        int a,b,r;
        scanf("%d %d", &a,&b);
        int z=euclid (a,b);
        printf("%d\n",z);
    }
    return 0;
}
