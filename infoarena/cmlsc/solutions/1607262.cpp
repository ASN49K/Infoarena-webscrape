#include <cstdio>
#define nmax 1030

using namespace std;

int a[nmax][nmax],x[nmax],y[nmax],st[nmax],vf;

int maxim(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&y[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=maxim(a[i-1][j],a[i][j-1]);
    printf("%d\n",a[n][m]);
    int i=n,j=m;
    while(a[i][j])
    {
        if(a[i][j]==a[i-1][j-1]+1)
        {
            st[++vf]=x[i];
            i--,j--;
        }
        else
        if(a[i][j]==a[i-1][j])
            i--;
        else
            j--;
    }
    for(int i=vf;i>=1;i--)
        printf("%d ",st[i]);
    return 0;
}
