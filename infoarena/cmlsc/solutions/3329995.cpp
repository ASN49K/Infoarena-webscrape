#include <iostream>
using namespace std;
int dp[1025][1025];
int main() {
    int M, N;
    cin >> M >> N;

    int A[1025], B[1025];
    for (int i = 1; i <= M; i++)
        cin >> A[i];
    for (int j = 1; j <= N; j++)
        cin >> B[j];


    // Construim tabelul dp
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }

    // Afisam lungimea maxima
    cout << dp[M][N] << "\n";

    // Reconstruim subsirul
    int i = M, j = N;
    int sol[1025], k = 0;

    while (i > 0 && j > 0) {
        if (A[i] == B[j]) {
            sol[k++] = A[i];
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Afisam subsirul (in ordine corecta)
    for (int x = k - 1; x >= 0; x--)
        cout << sol[x] << " ";

    return 0;
}
