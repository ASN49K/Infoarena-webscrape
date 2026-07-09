#include <fstream>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
vector <int> a, b, best;
vector <vector <int>> dp;

void init() {
    a = vector <int> (n + 1);
    b = vector <int> (m + 1);
//    best = vector <int> (max(n, m) + 1);
    dp = vector <vector <int>> (n + 1, vector <int>(m + 1));
}

void read() {
    fin >> n >> m;
    init();
    for(int i = 1; i <= n; i ++)
        fin >> a[i];
    for(int i = 1; i <= m; i ++)
        fin >> b[i];
}

void solve() {
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    for(int i = n, j = m; i && j;) {
        if(a[i] == b[j]) {
            best.push_back(a[i]);
            i --;
            j --;
        }
        else {
            if(dp[i - 1][j] > dp[i][j - 1]) {
                i --;
            }
            else {
                j --;
            }
        }
    }
}

void print() {
    fout << best.size() << '\n';
    for(auto it = best.rbegin(); it != best.rend(); ++it)
        fout << *it << " ";
}

int main() {
    read();
    solve();
    print();
}
