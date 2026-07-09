#include <iostream>
#include <fstream>
using namespace std;
const int Maxx=1e3+25;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int A[Maxx];
int B[Maxx];
int n,m,i,j,bst;
int dp[Maxx][Maxx];
int ans[Maxx];
int main()
{
    fin>>n>>m;
    for (i=1;i<=n;++i) fin>>A[i];
    for (i=1;i<=m;++i) fin>>B[i];
    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j)
            if (A[i]==B[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    for (i=n , j=m; i;)
        if (A[i]==B[j])
            ans[++bst]=A[i],--i,--j;
        else if (dp[i-1][j]<dp[i][j-1])
            --j;
        else
            --i;
    fout<<bst<<"\n";
    for (i=bst;i>0;--i) fout<<ans[i]<<" ";
    return 0;
}
