#include <cstdio>

using namespace std;

inline int CMMDC(int a, int b)
{
    int r=a%b;
    while(r)
    {
        a=b; b=r; r=a%b;
    }
    return b;
}

int main()
{
    int T,a,b;
    freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &a,&b);
        printf("%d\n", CMMDC(a,b));
    }
    return 0;
}
