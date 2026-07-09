#include <fstream>
#include <vector>

std::ifstream f("cmlsc.in");
std::ofstream g("cmlsc.out");

const int NMAX = 1025;
int n,m,a[NMAX],b[NMAX],dp[NMAX][NMAX];
std::vector<int>sol;

int main(){
    
    f >> n >> m;
    
    for(int i = 1;i <= n;++i)
        f >> a[i];
    
    for(int i = 1;i <= m;++i)
        f >> b[i];
    
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = std::max(dp[i - 1][j],dp[i][j - 1]);
    
    int k = dp[n][m];
    int i = n;
    int j = m;
    
    while(k){
        
        if(a[i] == b[j]){
            sol.push_back(a[i]);
            i--;
            j--;
            k--;
        }else if(dp[i - 1][j] == dp[i][j]){
            i--;
        }else if(dp[i][j - 1] == dp[i][j])
            j--;
    }
    
    g << dp[n][m] << '\n';
    
    for(int i = (int)sol.size() - 1;i >= 0;--i)
        g << sol[i] << ' ';
    
    return 0;
}
