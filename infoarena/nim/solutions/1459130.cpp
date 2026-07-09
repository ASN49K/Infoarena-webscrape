#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int t,n,x,rez,i,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&x);
        rez=x;
        for(j=2;j<=n;j++)
        {
            scanf("%d",&x);
            rez=rez^x;
        }
        if(rez%2==1)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
