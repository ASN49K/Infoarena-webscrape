#include <fstream>
#include <vector>

std::ifstream f("cmlsc.in");
std::ofstream g("cmlsc.out");

const int NMAX = 1030;
int s1[NMAX],s2[NMAX],n,m,dp[NMAX][NMAX];
std::vector<int>v;

void reconst(int i,int j,int k){

    while(k){

        if(s1[i] == s2[j]){
            v.emplace_back(s1[i]);
            i--;
            j--;
            k--;
        }else if(dp[i - 1][j] == k)
            i--;
        else if(dp[i][j - 1] == k)
            j--;
    }

    for(int i = v.size() - 1;i >= 0;--i)
        g << v[i] << ' ';
}

int main(){

    f >> n >> m;

    for(int i = 1;i <= n;++i)
        f >> s1[i];

    for(int j = 1;j <= m;++j)
        f >> s2[j];

    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
            if(s1[i] == s2[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = std::max(dp[i - 1][j],dp[i][j - 1]);

    g << dp[n][m] << '\n';

    reconst(n,m,dp[n][m]);

    return 0;
}
