#include <cstdio>
using namespace std;

inline int cmmdc(int x,int y)
{
    int r=x%y;

    while (r)
    {
        x=y;
        y=r;
        r=x%y;
    }

    return y;
}

int n,x,y;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&n);

    while (n--)
    {
        scanf("%d%d",&x,&y);

        printf("%d\n",cmmdc(x,y));
    }
    return 0;
}
