#include <stdio.h>
int main()
{
    freopen ("nim.in","r",stdin);
    freopen ("nim.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int x=0;x<t;x++)
    {
        int n;
        scanf("%d",&n);
        int rez=0,nr;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&nr);
            rez=rez^nr;
        }
        if(rez!=0) printf("DA\n");
        else printf("NU\n");
    }
}
