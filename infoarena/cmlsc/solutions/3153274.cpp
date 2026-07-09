#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int N, M;
    fin >> N >> M;
    vector <int> a(N + 1), b(M + 1);
    for (int i = 1;i <= N;++i) {
        fin >> a[i];
    }
    for (int i = 1;i <= M;++i) {
        fin >> b[i];
    }
    vector <vector <int>> dp(N + 1, vector <int>(M + 1, 0));
    for (int i = 1;i <= N;++i) {
        for (int j = 1;j <= M;++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
        }
    }
    vector <int> answer;
    int i = N, j = M;
    while (i >= 1 && j >= 1) {
        if (a[i] == b[j]) {
            answer.push_back(a[i]);
            i -= 1;
            j -= 1;
        }
        else {
            if (dp[i][j - 1] > dp[i - 1][j]) {
                j -= 1;
            }
            else {
                i -= 1;
            }
        }
    }
    reverse(answer.begin(), answer.end());
    fout << answer.size() << "\n";
    for (auto& x : answer) {
        fout << x << " ";
    }
    fin.close();
    fout.close();
    return 0;
}