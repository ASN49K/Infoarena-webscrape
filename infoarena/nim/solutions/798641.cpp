#include <cstdio>
using namespace std;
int main()
{
    int t,n,a,xormax;
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        xormax=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            xormax=xormax^a;
        }
        if(xormax)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
