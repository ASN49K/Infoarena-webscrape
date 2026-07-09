#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    int t;
    for(scanf("%d",&t);t;t--)
    {
        int n,x,s=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            s^=x;
        }
        if(s) printf("DA\n");
        else printf("NU\n");
    }
    return 0;
}
