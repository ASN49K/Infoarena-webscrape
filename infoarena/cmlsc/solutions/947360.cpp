#include <cstdio>

using namespace std;
int r[1025][1025],a[1025],b[1025],n,m,i,j;
int Mx(int x,int y)
{
    if (x>y) return x;
    else return y;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for (j=1; j<=m; j++)
        scanf("%d",&b[j]);
    for (i=1;i<=n;i++)
    if (a[i]==b[1] || r[i-1][1]==1) r[i][1]=1;
    for (i=1;i<=m;i++)
    if (a[1]==b[i] || r[1][i-1]==1) r[1][i]=1;
    for (i=2; i<=n; i++)
        for (j=2; j<=m; j++)
            if (a[i]==b[j]) r[i][j]=r[i-1][j-1]+1;
            else r[i][j]=Mx(r[i-1][j],r[i][j-1]);
    printf("%d\n",r[n][m]);
    i=n;
    j=m;
    while (r[i][j]!=0)
    {
        if (a[i]==b[j]) {printf("%d ",a[i]); i--;j--;}
        else {if (r[i-1][j]>r[i][j-1]) i--;
        else j--;}
    }
    return 0;
}
