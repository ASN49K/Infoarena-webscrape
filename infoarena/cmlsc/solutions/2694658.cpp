#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int A[1030],B[1030],n,m;
int dp[1030][1030];
int bst,sir[1030];
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>A[i];
    for(int i=1; i<=m; i++)
        f>>B[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(A[i]==B[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }


    int i=n,j=m;
    while(j>0)
    {
        if(A[i]==B[j])
        {
            sir[bst++]=A[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]<dp[i][j-1])
                j--;
            else i--;
        }
    }

    g<<bst<<'\n';
    for(int i=bst-1;i>=0;i--)
        g<<sir[i]<<" ";

    return 0;
}
