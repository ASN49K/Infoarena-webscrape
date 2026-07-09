#include <iostream>
#include <cstdio>
using namespace std;
int n,m,i,j,A[1025],B[1025],M[1025][1025],C[1025],k;
int main()
{

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%i",&n);
    scanf("%i",&m);
    for (i=1;i<=n;i++)
        scanf("%i",&A[i]);
    for (i=1;i<=m;i++)
       scanf("%i",&B[i]);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
    {
        if (A[i]==B[j]) M[i][j]=M[i-1][j-1]+1;
        else M[i][j]=max(M[i-1][j],M[i][j-1]);
    }
    cout<<M[n][m]<<'\n';
    while (i!=0)
    {
        if (A[i]==B[j])
        {
            C[k]=B[j];
            k++;
            i--;
            j--;
        }
        else if (M[i-1][j]<M[i][j-1]) j--;
        else i--;
    }
    for (i=k-1;i>=0;i--) cout<<C[i]<<" ";


}
