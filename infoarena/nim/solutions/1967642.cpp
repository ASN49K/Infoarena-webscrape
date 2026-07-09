#include <cstdio>
using namespace std;
int t,i,j,n,x,sol;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    for (i=1; i<=t; i++)
    {
        scanf("%d",&n);
        sol=0;
        for (j=1; j<=n; j++)
        {
            scanf("%d",&x);
            sol^=x;
        }
        if (sol) printf("DA\n");
        else printf("NU\n");
    }
    return 0;
}
