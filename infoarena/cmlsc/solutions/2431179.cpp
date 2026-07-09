#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1030],b[1030],v[1030],dp[1030][1030],m,n,k,i,j;
int main()
{
    fin>>m>>n;
    for (i=1; i<=m; i++)
        fin>>a[i];
    for (i=1; i<=n; i++)
        fin>>b[i];
    fin.close();

    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            if (a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                if (dp[i-1][j]>dp[i][j-1])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i][j-1];
    i=m; j=n;
    while (i>=0 && j>=0)
    {
        if (a[i]==b[j])
        {
            v[++k]=a[i];
            i--;
            j--;
        }
        else
            if (dp[i-1][j]<dp[i][j-1])
                j--;
            else
                i--;
    }

    fout<<k-1<<"\n";
    for (i=k-1; i>=1; i--)
        fout<<v[i]<<" ";
    fout.close();
    return 0;
}
