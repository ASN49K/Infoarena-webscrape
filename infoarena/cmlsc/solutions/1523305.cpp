#include <cstdio>
#include <queue>

using namespace std;

int n,m,ma,ma2;
int v1[1025],v2[1025],rez[1025];

struct{
    int l;
    char sus,stanga,comun;
}L[1025][1025];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",v1+i);
    for(i=1;i<=m;i++)
        scanf("%d",v2+i);

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
            {
                L[i][j].l=L[i-1][j-1].l+1;
                L[i][j].comun=1;
            }
            else if(L[i-1][j].l==L[i][j-1].l)
            {
                L[i][j].l=L[i-1][j].l;
                L[i][j].sus=L[i][j].stanga=1;
            }
            else if(L[i-1][j].l>L[i][j-1].l)
            {
                L[i][j].l=L[i-1][j].l;
                L[i][j].sus=1;
            }
            else
            {
                L[i][j].l=L[i][j-1].l;
                L[i][j].stanga=1;
            }
        }

    ma=L[n][m].l;
    printf("%d\n",ma);
    ma2=ma;
    i=n;j=m;
    while(ma2)
    {
        if(L[i][j].comun==1&&L[i][j].l==ma2)
        {
            rez[ma2]=v1[i];
            i--;j--;ma2--;
        }
        else if(L[i][j].sus==1)
            i--;
        else j--;
    }
    for(i=1;i<=ma;i++)
        printf("%d ",rez[i]);

/*    for(i=0;i<=n;i++)
    {for(j=0;j<=m;j++)
        {
            if(L[i][j].comun) printf("\\%d ",L[i][j].l);
            else if(L[i][j].sus&&L[i][j].stanga) printf("<^%d ",L[i][j].l);
            else if(L[i][j].sus) printf("^%d ",L[i][j].l);
            else printf("<%d ",L[i][j].l);
        }
    printf("\n\n");
    }*/

    return 0;
}
