#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int t,n,sol,x;
    scanf("%d",&t);
    for(int q=1;q<=t;q++)
    {
        scanf("%d",&n);
        sol=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            sol=sol^x;
        }
        if(sol==0) printf("NU\n");
        else printf("DA\n");
    }
    return 0;
}
