#include <fstream>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

vector <int> ans;

int m, n, lcs[1030][1030], v1[1030], v2[1030];

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> v1[i];
    }

    for(int i = 1; i <= m; ++i) {
        cin >> v2[i];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(v1[i] == v2[j]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    cout << lcs[n][m] << '\n';
    int i = n, j = m;

    while(lcs[i][j] > 0) {
        if(v1[i] == v2[j]) {
            ans.push_back(v1[i]);
            --i;
            --j;
        }
        else if(lcs[i - 1][j] > lcs[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }

    for(int k = ans.size() - 1; k >= 0; --k) {
        cout << ans[k] << ' ';
    }

    cout << '\n';
    return 0;
}
