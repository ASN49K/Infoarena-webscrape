#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int M, N;
    fin >> M >> N;

    vector<int> A(M + 1), B(N + 1);
    for (int i = 1; i <= M; i++) fin >> A[i];
    for (int j = 1; j <= N; j++) fin >> B[j];

    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));

    // Calculăm matricea DP
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Lungimea maximă
    int MAX = dp[M][N];
    fout << MAX << "\n";

    // Reconstruim un subsir comun
    vector<int> subsir;
    int i = M, j = N;
    while (i > 0 && j > 0) {
        if (A[i] == B[j]) {
            subsir.push_back(A[i]);
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    // Subsirul e construit invers → îl întoarcem
    for (int k = subsir.size() - 1; k >= 0; k--)
        fout << subsir[k] << " ";

    fout.close();
    fin.close();
    return 0;
}

