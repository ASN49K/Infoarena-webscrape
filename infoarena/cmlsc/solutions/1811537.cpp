#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int a[1030][1030];

int main()
{
    int n, m; cin >> n >> m;
    int *v = new int[n + 2];
    int *t = new int[m + 2];
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> t[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[i] == t[j]) {
                a[i][j] = a[i - 1][j - 1] + 1;
            } else {
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            }
        }
    }

    vector <int> secv;

    int i = n;
    int j = m;
    while (true) {
        if (a[i][j] == a[i - 1][j]) {
            --i;
        } else if (a[i][j] == a[i][j - 1]) {
            --j;
        } else {
            secv.push_back(v[i]);
            --i;
            --j;
        }

        if (i == 0 || j == 0) {
            break;
        }
    }

    cout << a[n][m] << '\n';
    for (vector<int>::reverse_iterator it = secv.rbegin(); it != secv.rend(); ++it) {
        cout << *it << ' ';
    }

    return 0;
}
