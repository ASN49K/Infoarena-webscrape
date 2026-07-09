#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int M, N;
    fin >> M >> N;

    vector<int> A(M);
    vector<int> B(N);

    for (int i = 0; i < M; i++) {
        fin >> A[i];
    }
    for (int j = 0; j < N; j++) {
        fin >> B[j];
    }

    // Matricea dp de dimensiune (M+1) x (N+1)
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));

    // Construim matricea dp
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Lungimea maximă a subsirului comun
    int MAX = dp[M][N];
    fout << MAX << endl;

    // Reconstruim subsirul comun
    vector<int> lcs;
    int i = M, j = N;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            lcs.push_back(A[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Inversăm pentru a obține subsirul în ordinea corectă
    reverse(lcs.begin(), lcs.end());

    // Scriem subsirul comun
    for (int x : lcs) {
        fout << x << " ";
    }
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}
