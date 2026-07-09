#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define NMAX 1024

int a[NMAX + 1];
int b[NMAX + 1];
int dp[NMAX + 1][NMAX + 1];

void backTrack(int i, int j){
    if (i == 0 || j == 0) return;
    if (a[i] == b[j]){
        backTrack(i - 1, j - 1);
        fout << a[i] << " ";
    }
    else if (dp[i - 1][j] > dp[i][j - 1]){
        backTrack(i - 1, j);
    }
    else{
        backTrack(i, j - 1);
    }
}

int main()
{
    int N, M;
    fin >> N >> M;
    for (int i = 1; i <= N; i++){
        fin >> a[i];
    }
    for (int j = 1; j <= M; j++){
        fin >> b[j];
    }
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j]){
                dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
        }
    }
    fout << dp[N][M] << '\n';
    backTrack(N, M);
    return 0;
}
