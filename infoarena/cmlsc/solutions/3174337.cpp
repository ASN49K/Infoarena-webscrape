#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int arr[1030], arr2[1030], n, m;
int dp[1030][1030];

int sol[1030], solution;

void lcs() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (arr[i] == arr2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
}

void road() {
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (arr[i] == arr2[j]) {
            sol[solution++] = arr[i];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
}

void print(int k) {
    if (k == 0) return;
    fout << sol[k - 1] << " ";
    print(k - 1);
}

int main() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> arr[i];
    for (int i = 1; i <= m; i++)
        fin >> arr2[i];

    lcs();

    fout << dp[n][m] << "\n";

    road();
    print(solution);
}