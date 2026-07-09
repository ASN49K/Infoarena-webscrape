#include <cstdio>

using namespace std;
int euclid(int a, int b);
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t, x, y, i;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",euclid(x,y));
    }
    return 0;
}
int euclid(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
