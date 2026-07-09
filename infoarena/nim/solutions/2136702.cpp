#include<bits/stdc++.h>
using namespace std;
int n,xorsum,x,t;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        xorsum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            xorsum^=x;
        }
        if(!xorsum) printf("NU\n");
            else printf("DA\n");
    }

    return 0;
}
