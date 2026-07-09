#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int t,n,x,rez;
    scanf("%d",&t);
    for(; t; t--)
    {
        scanf("%d",&n);
        rez = 0;
        for (; n; n--)
        {
            scanf("%d",&x);
            rez^=x;
        }
        if (rez)
            printf("DA\n");
        else
            printf("NU\n");
    }
}
