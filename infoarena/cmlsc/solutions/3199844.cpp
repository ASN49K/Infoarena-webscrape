#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[256], B[256], M, N;

int nmax()
{
    int dp[M][N];

    for(int i=0; i<max(M,N); i++)
        dp[i][0] = dp[0][i] = 0;

    for(int i=1; i<M; i++)
        for(int j=1; j<N; j++)
            if(A[i] == B[j])
                dp[i][j] = dp[i-1][j-1] +1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    return dp[M-1][N-1];
}

int main()
{
    fin>>M>>N;
    for(int i=0; i<M; i++)
        fin>>A[i];
    for(int i=0; i<N; i++)
        fin>>B[i];

    fout<<nmax();
}
