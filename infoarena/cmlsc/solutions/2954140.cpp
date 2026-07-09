#include <bits/stdc++.h>

#define NMAX 1024

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[NMAX + 1];
int b[NMAX + 1];
int dp[NMAX + 1][NMAX + 1];

void afisareDP(int x, int y){
    if(y == 0){
        return;
    }

    if(a[x] == b[y]){
        afisareDP(x - 1, y - 1);
        fout << a[x] << ' ';
    }
    else if(dp[x - 1][y] != 0 && (dp[x - 1][y] == dp[x][y])){
        afisareDP(x - 1, y);
    }
    else {
        afisareDP(x, y - 1);
    }
}

int main()
{
    int N, M;
    fin >> N >> M;

    for(int i = 1; i <= N; i++){
        fin >> a[i];
    }
    for(int j = 1; j <= M; j++){
        fin >> b[j];
    }


    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    fout << dp[N][M] << "\n";

    afisareDP(N, M);

    return 0;
}
