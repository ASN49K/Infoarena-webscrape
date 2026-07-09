#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x[1050],y[1050],a[1050][1050];
void afis(int i, int j){
    if (i==0 || j==0) return;
    if (x[i]==y[j])
    {
        afis(i-1,j-1);
        printf("%d ",x[i]);
    }
    else
    {
        if (a[i][j-1]>a[i-1][j])
            afis(i,j-1);
        else afis(i-1,j);
    }
}
int main()
{
    int i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i)
        scanf("%d",&x[i]);
    for (i=1;i<=m;++i)
        scanf("%d",&y[i]);
    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j)
            if (x[i]==y[j])
                a[i][j]=1+a[i-1][j-1];
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
    printf("%d\n",a[n][m]);
    afis(n,m);
    printf("\n");
    return 0;
}
