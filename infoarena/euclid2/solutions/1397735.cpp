#include <bits/stdc++.h>

using namespace std;
int t,x,y;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    for(;t;t--)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",__gcd(x,y));
    }
    return 0;
}
