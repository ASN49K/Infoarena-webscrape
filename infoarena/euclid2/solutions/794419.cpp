#include <cstdio>

using namespace std;

int nr,a,b;

int euclid(int a, int b)
{
    int r;
    while (a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&nr);
    for (int i=1; i<=nr; i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",euclid(a,b));
    }
    return 0;
}
