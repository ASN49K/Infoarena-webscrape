#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n;
int A[1025], B[1025];
int dp[1025][1025];

void citire(){
    for (int i = 1; i <= m; i++)
        fin >> A[i];
    for (int i = 1; i <= n; i++)
        fin >> B[i];
}

int solve(){

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j++)
            if (A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));

    return dp[m][n];
}

int main()
{
    fin >> m >> n;
    citire();

    fout << solve();

    return 0;
}
