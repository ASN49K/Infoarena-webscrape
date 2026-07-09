#include <bits/stdc++.h>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

const int SIZE = 1030;

int n, m;
int a[SIZE], b[SIZE];

// dp[i][j] = lungimea maxima a unui subsir comun a[1...i] si b[1..j]
int dp[SIZE][SIZE];
// rezultatul trebuie sa fie in dp[n][m], reconstituirea se face cu o stiva


int64_t max(std::vector<int64_t> v){ return *std::max_element(v.begin(), v.end()); }

int64_t min(std::vector<int64_t> v){ return *std::min_element(v.begin(), v.end()); }

int main() 
{
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
        fin >> a[i];
    for(int j = 1; j <= m; ++j)
        fin >> b[j];
    
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max({dp[i - 1][j], dp[i][j - 1]});
    
    fout << dp[n][m] << "\n";
    // reconstituire
    std::vector<int> stack;
    for(int i = n, j = m; dp[i][j]; )
        if(a[i] == b[j])
            stack.emplace_back(a[i]), i--, j--;
        else if(dp[i][j] == dp[i][j - 1])
            j--;
        else if(dp[i][j] == dp[i - 1][j])
            i--;
    
    for(int i = stack.size() - 1; i >= 0; --i)
        fout << stack[i] << " ";
    
    return 0;
}