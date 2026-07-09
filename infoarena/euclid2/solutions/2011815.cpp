#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a % b);
}
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int i,T,x,y;
    scanf("%d", &T);
    for(i=1; i<=T; i++)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",gcd(x,y));
    }

    return 0;
}
