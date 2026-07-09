#include <cstdio>

using namespace std;

int cmmdc(int x, int y)
{
    if(x%y==0)
        return y;

    int r=x%y;
    x=y;
    y=r;
    cmmdc(x, r);

}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int n, a, b;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a,b));
    }


    return 0;
}
