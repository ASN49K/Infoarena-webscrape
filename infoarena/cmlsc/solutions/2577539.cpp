#include <fstream>
#include <vector>
#define NMAX 1030
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, a[NMAX], b[NMAX],
    dp[NMAX][NMAX];

void read() {
    in >> n >> m;
    for(int i = 1; i <= n; i++)
        in >> a[i];
    for(int i = 1; i <= m; i++)
        in >> b[i];
}

void solve() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
}

void print() {
    vector <int> ans;
    int x = n, y = m;
    while(x > 0 && y > 0) {
        if(a[x] == b[y]) {
            ans.push_back(a[x]);
            x--;
            y--;
        }
        else if(dp[x][y] == dp[x-1][y])
            x--;
        else
            y--;
    }
    out << ans.size() << '\n';
    for(int i = (int)ans.size()-1; i >= 0; i--)
        out << ans[i] << " ";
}

int main() {
    read();
    solve();
    print();
    

    in.close();
    out.close();
    return 0;
}