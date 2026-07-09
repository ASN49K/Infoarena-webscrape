#include <fstream>
#include <vector>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int maxn = 1030;

int a[maxn], b[maxn];
int dp[maxn][maxn];
vector<int> sol;

int main(){
    int n, m;
    f >> n >> m;
    for(int i = 1; i <= n; ++i) f >> a[i];
    for(int i = 1; i <= m; ++i) f >> b[i];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            dp[i][j] = dp[i-1][j-1] + (int)(a[i]==b[j]);
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }
    g << dp[n][m] << '\n';
    int i = n;
    int j = m;
    while(i && j){
        if(a[i] == b[j]){
            sol.push_back(a[i]);
            --i;
            --j;
            continue;
        }
        if(dp[i][j] == dp[i-1][j]){
            --i;
        }
        else --j;
    }

    for(i = sol.size()-1; i >= 0; --i){
        g << sol[i] << ' ';
    }
    return 0;
}
