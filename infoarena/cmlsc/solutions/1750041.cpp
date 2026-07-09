#include <fstream>
#include <vector>

#define maxn 1030
using namespace std;

int n, m;
int dp[maxn][maxn];
int a[maxn];
int b[maxn];
vector<int> sol;

int main() {
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    in >> n >> m;

    for (int i = 1; i <= n; i++)
        in >> a[i];
    for (int j = 1; j <= m; j++)
        in >> b[j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        }

    int i = n, j = m;

    while (i != 0 && j != 0) {
        if (a[i] == b[j]) {
            sol.push_back(a[i]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else
            j--;
    }

    out << sol.size() << "\n";
    for (i = sol.size() - 1; i >= 0; i--) {
        out << sol[i] << " ";
    }
    return 0;
}