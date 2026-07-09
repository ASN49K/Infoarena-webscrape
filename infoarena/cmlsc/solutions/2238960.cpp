#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int NMAX = 1030;

int dp[NMAX][NMAX];
int a[NMAX], b[NMAX];
struct Data {
    int x, y;
    Data() {
        x = 0;
        y = 0;
    }
}from[NMAX][NMAX];

int main() {
    int n, m;
    in >> n >> m;
    for(int i = 1; i <= n; i ++)
        in >> a[i];
   for(int i = 1; i <= m; i ++)
        in >> b[i];

   for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                from[i][j].x = i - 1;
                from[i][j].y = j - 1;
            }
            else {
                if(i == 3 && j == 1)
                    i = 3;
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if(dp[i - 1][j] > dp[i][j - 1]) {
                    from[i][j].x = i - 1;
                    from[i][j].y = j;
                }
                else {
                    from[i][j].x = i;
                    from[i][j].y = j - 1;
                }
            }
        }
    }
    out << dp[n][m] << "\n";
    int x = n, y = m;
    vector<int> v;
    while(x != 0 && y != 0) {
        if(a[x] == b[y])
            v.push_back(a[x]);
        int cx = x, cy = y;
        x = from[cx][cy].x;
        y = from[cx][cy].y;
    }
    for(int i = v.size() - 1; i >= 0; i --)
        out << v[i] << " ";
    return 0;
}
