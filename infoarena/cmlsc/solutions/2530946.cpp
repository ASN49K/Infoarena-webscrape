#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int M,N,A[1030],B[1030],dp[1030][1030],C[1030],P;

int main()
{
    fin >> M >> N;
    int i,j,poz=1;
    for (i=1;i<=M;++i)
    {
        fin >> A[i];
    }
    for (i=1;i<=N;++i)
    {
        fin >> B[i];
    }
    for (i=1;i<=M;++i)
    {
        for (j=1;j<=N;++j)
        {
            if (A[i]==B[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                ++P;
                C[P]=A[i];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    fout << dp[M][N] << '\n';
    for (i=1;i<=P;++i)
    {
        fout << C[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
