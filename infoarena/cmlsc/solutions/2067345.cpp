#include <fstream>
#include <vector>
#include <stack>

using namespace std;

int main() {
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");    
int n, m;

in >> n >> m;
vector<int> a(n+1), b(m+1);
vector< vector<int> > dp (n+1, vector<int> (m+1));
stack<int> s;

for (int i = 0; i < n; ++i) {
    in >> a[i+1];
    dp[i][0] = 0;
}
dp[n][0] = 0;

for (int i = 0; i < m ; ++i) {
    in >> b[i+1];
dp[0][i] = 0;
}
dp[0][m] = 0;

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <=m; j++) {
        if (a[i] == b[j]) {
            dp[i][j] = dp[i-1][j-1] + 1;
        } else {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
}
}
    }

    int i = n, j = m;
    while (dp[i][j] != 0) {
        if (dp[i-1][j] == dp[i][j]) {
            i --;
continue;
        }
        if (dp[i][j-1] == dp[i][j]) {
            j--;
            continue;
        }
        s.push(a[i]);
        i--;
        j--;
}
    
    out << dp[n][m] << '\n';
    while (! s.empty()) {
        out << s.top() << ' ';
        s.pop();
    }

    return 0;
}

