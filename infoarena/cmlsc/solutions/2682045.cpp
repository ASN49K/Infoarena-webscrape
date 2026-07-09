#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1030], b[1030], dp[1030][1030];
// dp[i][j] - nr de caractere potrivite pana la poz i din a si j din b
// dp[i][j] = 1 + dp[i - 1][j - 1] daca a[i]==b[j] sau
// d[i][j] = max(dp[i - 1][j], dp[i][j - 1])


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    
    for (int i = 1; i <= m; i++)
        fin >> b[i];


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    fout << dp[n][m] << "\n";
    int i = n, j = m;
    int x = dp[n][m];
    vi solution;
    while (x > 0) {
        if (a[i] == b[j]) {
            solution.push_back(a[i]);
            x--;
            i--; j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    for (int i = dp[n][m] - 1; i >= 0; i--) {
        fout << solution[i] << " ";
    }
    fout << "\n";


    return 0;
}