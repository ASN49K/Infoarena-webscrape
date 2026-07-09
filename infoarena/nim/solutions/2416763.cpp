#include <bits/stdc++.h>
/// TONI BO$$ was here
/// #MLC

using namespace std;

int main()
{
    int t,n,x,sumxor;
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        sumxor=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&x);
            sumxor^=x;
        }
        if(sumxor) printf("DA\n");
        else printf("NU\n");
    }

    return 0;
}
