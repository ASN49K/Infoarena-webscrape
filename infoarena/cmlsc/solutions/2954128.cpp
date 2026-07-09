#include <bits/stdc++.h>

#define NMAX 1024

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[NMAX + 1];
int b[NMAX + 1];
int dp[NMAX + 1][NMAX + 1];
vector <int> sol;

void afisareDP(int N, int M){
    if(N <= 0 || M <= 0){
        return;
    }

    for(int i = N; i >= 1; i--){
        for(int j = M; j >= 1; j--){
            if(a[i] == b[j]){
                sol.push_back(a[i]);

                afisareDP(i - 1, j - 1);
                return;
            }
        }
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

    /*
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

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */

    afisareDP(N, M);

    fout << sol.size() << "\n";
    for(int i = sol.size() - 1; i >= 0; i--){
        fout << sol[i] << ' ';
    }
    fout << "\n";

    return 0;
}
