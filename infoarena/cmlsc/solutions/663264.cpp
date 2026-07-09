#include <cstdio>
#define max(a,b) ((a>b)?a:b)
using namespace std;
int s[1024],d[1025][1025],a[1025],b[1025],i,j,n,m,nr;
void swp(int a,int b)
{
    int aux;
    aux=a;
    a=b;
    b=aux;
}
int main()
    {
        freopen("cmlsc.in","r",stdin);
        freopen("cmlsc.out","w",stdout);
        scanf("%d%d",&n,&m);
           for (i=1 ;i<=n; i++) scanf("%d",&a[i]);
           for (i=1 ;i<=m; i++) scanf("%d",&b[i]);
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                 if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
                 else d[i][j]=max(d[i][j-1],d[i-1][j]);
        
        while (n>=1)
        {
            if (a[n]==b[m])
            {
                nr++;
                s[nr]=a[n];
                n--;
                m--;
            }
            else
            if (d[n][m-1]>d[n-1][m]) m--;
            else n--;
        }
        printf("%d\n",nr);
        for (i=nr;i>=1 ;i--)
            printf("%d ",s[i]);
    return 0;
    }
