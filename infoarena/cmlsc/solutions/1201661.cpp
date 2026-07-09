#include <cstdio>
#include <algorithm>
using namespace std;
int a[1025],b[1025];
int lcs[1025][1025],sir[1025];
int m,n,lg;
void R()
{
    freopen("cmlsc.in","r",stdin);
    scanf("%d %d",&n, &m);
    int i;
    for(i=1; i<=n; i++)
        scanf("%d ",&a[i]);
    for(i=1; i<=m; i++)
        scanf("%d ",&b[i]);
       // printf("%d ",m);
}
void LCS()
{
    int i,j;
    for(i=1; i<=n; i++ )
        for(j=1; j<=m; j++)
        if(a[i]==b[j])
        lcs[i][j]=lcs[i-1][j-1]+1;
        else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);


}
int main()
{
    R();
    LCS();
    int i,j;
    for(i=1,j=1; i<=n && j<=m; )
        if(a[i]==b[j])
    {
        sir[++lg]=a[i]; i++; j++;
    }
    else if (lcs[i+1][j]<lcs[i][j+1])
        j++;
    else i++;
    freopen("cmlsc.out","w",stdout);
    printf("%d\n",lg);
    for(i=1; i<=lg; i++)
        printf("%d ",sir[i]);

    return 0;
}
