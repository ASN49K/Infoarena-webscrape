#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",__gcd(x,y));
    }
    return 0;
}
