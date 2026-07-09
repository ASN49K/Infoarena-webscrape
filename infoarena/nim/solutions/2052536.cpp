#include <bits/stdc++.h>
using namespace std;

int T,n,x;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);

        int xorsum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            xorsum^=x;
        }

        if(xorsum)
            printf("DA\n");
        else printf("NU\n");
    }

    return 0;
}
