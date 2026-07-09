#include<cstdio>
using namespace std;
int t,n,xorsum,x;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    for(;t;t--)
    {
        scanf("%d",&n);
        for(xorsum=0;n;n--)
        {
            scanf("%d",&x);
            xorsum^=x;
        }
        if(xorsum) printf("DA\n");
        else printf("NU\n");
    }
    return 0;
}
