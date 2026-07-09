#include<stdio.h>

using namespace std;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int t,n;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        int xsum=0;
        for (int i=1; i<=n; ++i)
        {
            int x;
            scanf("%d",&x);
            xsum^=x;
        }
        if (xsum) printf("DA\n");
            else printf("NU\n");
    }
    return 0;

}
