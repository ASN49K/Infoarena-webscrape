#include <cstdio>
using namespace std;
long int T,x,y;
int Euclid(long int a,long int b)
{
    int r;
    while (a != b)
    {
        r = b%a;
        a=b;
        b=r;
    }
    return b;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%ld\n",&T);
    for (int i = 1; i <= T; i++)
    {
        scanf("%ld%ld\n",&x,&y);
        printf("%d\n",Euclid(x,y));
    }
}
