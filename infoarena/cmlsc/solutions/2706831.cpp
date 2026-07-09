#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m;
int A[1030],B[1030],Dp[1030][1030];
int sir[1030],bst;
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>A[i];

    for(int i=1; i<=m; i++)
        f>>B[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(A[i]==B[j])
                Dp[i][j]=Dp[i-1][j-1]+1;
            else Dp[i][j]=max(Dp[i-1][j],Dp[i][j-1]);
        }

    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(A[i]==B[j])
        {
            sir[bst++]=A[i];
            i--;
            j--;
        }
        else
        {
            if(Dp[i-1][j]<Dp[i][j-1])
                j--;
            else i--;
        }

    }

    g<<Dp[n][m]<<'\n';
    for(int i=bst-1; i>=0; i--)
        g<<sir[i]<<" ";
    return 0;
}
