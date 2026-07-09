#include<algorithm>
using namespace std;

#define DIM 1030

int n,m,bst[DIM][DIM],a[DIM],b[DIM],sol[DIM];

void solve ()
{
    int i,j;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j])
                bst[i][j]=bst[i-1][j-1]+1;
            else
                bst[i][j]=max(bst[i-1][j],bst[i][j-1]);
}

void drum ()
{
    int i=n,j=m,vf=0;
    while (i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            sol[++vf]=a[i];
            --i;
            --j;
        }
        else
        {
            if(bst[i][j-1]>bst[i-1][j])
                --j;
            else
                --i;
        }
    }
}

int main ()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i;

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(i=1;i<=m;++i)
        scanf("%d",&b[i]);
    solve ();
    drum ();
    printf("%d\n",bst[n][m]);
    for(i=bst[n][m];i>0;--i)
        printf("%d ",sol[i]);
    return 0;
}
