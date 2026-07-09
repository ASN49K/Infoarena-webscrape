#include <cstdio>

using namespace std;

typedef long long ll;

int T;

inline int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        int kol1,kol2;
        scanf("%d%d",&kol1,&kol2);
        printf("%d\n",gcd(kol1,kol2));
    }
    return 0;
}
