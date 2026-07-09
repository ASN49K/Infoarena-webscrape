#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define limn 1025

short A[limn], B[limn];
short N, M;
short dp[limn][limn];
short res[limn];

void afisare() {
    short dr = dp[N][M];
    short i, j;
    i = N;
    j = M;
    while (i >= 1 && j >= 1) {
        if (A[i] == B[j]) {
            res[dr] = A[i];
            dr--;
            i--;
            j--;
        }
        if (dp[i][j-1] < dp[i-1][j]) {
            i--;
        }
        else {
            j--;
        }
    }
    dr = dp[N][M];
    for(i = 1; i <= dr; i++) {
        fout << res[i] << " ";
    }
}


int main()
{
    fin >> N >> M;
    for(short i = 1; i <= N; i++)
        fin >> A[i];
    for(short i = 1; i <= M; i++)
        fin >> B[i];
    for(short i = 1; i <= N; i++) {
        for(short j = 1; j <= M; j++) {
            if(A[i] == B[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    fout << dp[N][M] << "\n";
    afisare();

    fin.close();
    return 0;
}
