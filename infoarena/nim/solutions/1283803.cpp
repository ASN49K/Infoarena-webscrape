#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    int t,n,x;
    for(scanf("%d",&t);t;t--)
    {
        scanf("%d",&n);
        int a=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            a^=x;
        }
        if(a) printf("DA\n");
        else printf("NU\n");
    }
    return 0;
}
