#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[1050],b[1050],D[1050][1050];
void afis(int i, int j)
{
    if (!i || !j) return ;
    if (a[i]==b[j])
    {
        afis(i-1,j-1);
        printf("%d ",a[i]);
    }
    else
    {
        if (D[i-1][j]>D[i][j-1])
            afis(i-1,j);
        else
            afis(i,j-1);
    }
}
int main()
{
    int i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);
    for (i=1;i<=m;++i)
        scanf("%d",&a[i]);
    for (i=1;i<=n;++i)
        scanf("%d",&b[i]);
    for (i=1;i<=m;++i)
        for (j=1;j<=n;++j)
            if (a[i]==b[j])
                D[i][j]=1+D[i-1][j-1];
            else
                D[i][j]=max(D[i-1][j],D[i][j-1]);
    printf("%d\n",D[m][n]);
    afis(m,n);
    printf("\n");
    return 0;
}
