#include <cstdio>
using namespace std;

int p[1025][1025],n,m,a[1025],b[1025],max,k[1025],k1;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            if (b[i]==a[j])
                p[i][j]=1+p[i-1][j-1];
            else
                if (p[i-1][j]>=p[i][j-1] && p[i-1][j]>=p[i-1][j-1])
                    p[i][j]=p[i-1][j];
                else
                    if (p[i][j-1]>=p[i-1][j] && p[i][j-1]>=p[i-1][j-1])
                        p[i][j]=p[i][j-1];
                    else
                        p[i][j]=p[i-1][j-1];
        }
    int i,j;
    i=m;
    j=n;
    printf("%d\n",p[m][n]);
    /*k[k1]=p[m][n];
    k1++;
    i--;
    j--;*/
    while (i>0 && j>0)
    {
        if (b[i]==a[j])
        {
            k[k1]=a[j];
            k1++;
            i--;
            j--;
        }
        else
        {
            if (p[i-1][j]>p[i][j-1])
                i--;
            else
                j--;
        }
    }
    for (int i=k1-1;i>=0;i--)
        printf("%d ",k[i]);
    return 0;
}
