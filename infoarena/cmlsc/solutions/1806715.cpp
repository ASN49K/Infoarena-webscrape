#include <cstdio>
using namespace std;
int n,m,i,j,k;
int main()
{
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    int v[1015],w[1015],d[1015][1015],yay[1015];
    scanf ("%d%d",&n,&m);
    for (i=1;i<=n;i++)
        scanf ("%d",&v[i]);
    for (i=1;i<=m;i++)
        scanf ("%d",&w[i]);
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            if (v[i]==w[j])
                d[i][j]=1+d[i-1][j-1];
            else
            {
                if(d[i-1][j]>=d[i][j-1])
                {
                    d[i][j]=d[i-1][j];
                }
                else
                {
                    d[i][j]=d[i][j-1];
                }
            }
        }
    }
    printf ("%d\n",d[n][m]);
    i=n;
    j=m;
    k=0;
    while (d[i][j]){
        if (v[i]==w[j]){
            yay[k++]=v[i];
            i--;
            j--;
        }
        else {
            if (d[i-1][j]>d[i][j-1])
                i--;
            else j--;
        }
    }
    for (i=k;i>0;i--)
        printf ("%d ",yay[i]);
        return 0;
}
