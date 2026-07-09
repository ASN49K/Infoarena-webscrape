#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int N = (1<<10) + 7;

short int v[2][N], ans[N];
int d[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> v[1][i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> v[2][i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[1][i] == v[2][j]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }
    cout << d[n][m] << "\n";
    int i(n), j(m), l(1);
    while (i > 0 && j > 0) {
        if (v[1][i] == v[2][j]) {
            ans[d[n][m] - l++] = v[1][i];
            --i;
            --j;
        }
        else if (d[i - 1][j] > d[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }
    for (int i = 0; i < d[n][m]; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
