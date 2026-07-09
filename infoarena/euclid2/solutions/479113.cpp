#include<algorithm>
using namespace std;

inline int solve (int a,int b)
{
    int r;
    while(b)
    {
        r=b%a;
        a=b;
        b=r;
    }
    return a;
}

int main ()
{
    freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);
    int i,t,a,b;

    scanf("%d",&t);
    for(i=1;i<=t;++i)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",solve (a,b));
    }
    return 0;
}
