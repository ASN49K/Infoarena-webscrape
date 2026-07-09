#include<cstdio>
using namespace std;

int main ()
{
    int sum,t,z,n,i,x;
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    for (z=1; z<=t; z++)
    {
        scanf("%d",&n);
        sum=0;
        for (i=1; i<=n; i++)
        {
            scanf("%d",&x);
            sum^=x;
        }
        if (sum)
            printf("DA\n");
        else printf("NU\n");
    }
    return 0;
}

