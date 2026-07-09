#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main()
{

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
int a, b, t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {
    scanf("%d %d", &a, &b);
        printf("%d\n", __gcd(a, b));

    }

    return 0;
}
