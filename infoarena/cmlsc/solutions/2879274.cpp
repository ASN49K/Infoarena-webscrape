#include <fstream>
#include <iostream>
#include <vector>
#define N 1025

using namespace std;

/*
dp[i][j] = cel mai lung subsir comun
al sirurilor pana la A[j] si B[i]
*/

int a[N], b[N], n, m;
int dp[N][N];

void read() {
    ifstream f("cmlsc.in");
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> a[i];
    for(int i = 1; i <= m; ++i)
        f >> b[i];
    f.close();
}

void write(vector<int> s) {
    ofstream g("cmlsc.out");
    g << s.size() << endl;
    for(auto i : s)
        g << i << " ";
    g << endl;
    g.close();
}

void backtrack(vector<int>&s, int i, int j) {
    if(i == 0 || j == 0)
        return;
    if(a[i] == b[j]) {
        s.insert(s.begin(), a[i]);
        backtrack(s, i - 1, j - 1);
    }
    else if(dp[i][j - 1] > dp[i - 1][j])
        backtrack(s, i, j - 1);
        else
            backtrack(s, i - 1, j);
}

void solve() {
    read();
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j],
                               dp[i][j - 1]);
    vector<int> sol;
    backtrack(sol, n, m);
    write(sol);
}

int main()
{
    solve();
    return 0;
}
