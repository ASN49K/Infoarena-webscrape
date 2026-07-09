#include <bits/stdc++.h>
int gcd(int a,int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int T,a,b;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
