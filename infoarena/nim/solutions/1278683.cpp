#include <cstdio>
using namespace std;
int t,n,x,s;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    for(;t;t--)
    {
        scanf("%d",&n);
        for(s=0;n;n--)
        {
            scanf("%d",&x);
            s^=x;
        }
        s?printf("DA"):printf("NU");
    }
    return 0;
}
