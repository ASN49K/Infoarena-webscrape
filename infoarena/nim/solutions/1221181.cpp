#include<cstdio>
using namespace std;
int t,n,x,s;
int main()
{
    int i,j;
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    for (i=1;i<=t;++i)
    {
        s=0;
        scanf("%d",&n);
        for (j=1;j<=n;++j)
        {
            scanf("%d",&x);
            s^=x;
        }
        if (!s) printf("NU\n");
        else printf("DA\n");
    }
    return 0;
}
