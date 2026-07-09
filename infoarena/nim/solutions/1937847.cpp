#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int t,nr,x,y;
    scanf("%d",&t);
    for (int i=1;i<=t;++i)
    {
        scanf("%d",&nr);
        scanf("%d",&x);
        for (int j=2;j<=nr;++j)
        {
            scanf("%d",&y);
            x=x xor y;
        }
        if (x)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
