#include<cstdio>

using namespace std;

int i,n,t,j,s,x;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        s=0;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&x);
            s^=x;
        }
        if(s>0)
        {
            printf("DA\n");
        }
        else
        {
            printf("NU\n");
        }
    }
    return 0;
}
