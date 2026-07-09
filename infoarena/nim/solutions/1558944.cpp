#include <cstdio>

using namespace std;
int t,n,x,i,sol;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sol=0;
        for(i=1; i<=n; ++i)
        {
            scanf("%d",&x);
            sol^=x;
        }
        if(sol)
            printf("DA\n");
        else printf("NU\n");
    }
    return 0;
}
