#include <iostream>
#include <cstdio>
using namespace std;
int i,j,M[1025][1025],A[1025],B[1025],n,m,sir[1025];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++)
        scanf("%d",&A[i]);
    for (i=1;i<=m;i++)
        scanf("%d",&B[i]);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
    {
        if (A[i]==B[j]) M[i][j]=M[i-1][j-1]+1;
        else M[i][j]=max(M[i-1][j],M[i][j-1]);
    }
    cout<<M[n][m]<<'\n';
    int p=0;
    for (i=n,j=m;i;)
    {
        if (A[i]==B[j])
        {
            sir[++p]=A[i];i--;j--;
        }
        else if (M[i-1][j]<M[i][j-1]) --j;
        else --i;
    }
    for (i=p;i>0;i--)
    {
        cout<<sir[i]<<" ";
    }
}
