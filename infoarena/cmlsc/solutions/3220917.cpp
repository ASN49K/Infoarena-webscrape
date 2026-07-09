// Made by https://github.com/bg16-2009

#include <fstream>
#include <vector>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int dp[1029][1029];
int main() {
    int n, m, v1[1029], v2[1029];
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fin >> v1[i];
    }
    for (int i = 1; i <= m; i++) {
        fin >> v2[i];
    }
    std::vector<int> r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v1[i] == v2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                r.push_back(v1[i]);
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    fout << dp[n][m]<<"\n";
    for(int x:r){
        fout<<x<<" ";
    }
    fin.close();
    fout.close();
    return 0;
}
