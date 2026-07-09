#include<cstdio>
using namespace std;
int t,test,i,rez,n,x;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    for(test=1;test<=t;test++)
    {
        scanf("%d",&n);
        scanf("%d",&rez);
        for(i=2;i<=n;i++)
        {
            scanf("%d",&x);
            rez^=x;
        }
        if(rez)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
