#include <fstream>
#include <vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int NMAX = 1e3 + 30;
int dp[NMAX + 5][NMAX + 5];
int s1[NMAX + 5];
int s2[NMAX + 5];
vector<int> ans;

int main()
{
    int n, m;
    in >> n >> m;
    for(int i = 1; i <= n; i++)
        in >> s1[i];
    for(int i = 1; i <= m; i++)
        in >> s2[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(s1[i] == s2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    out << dp[n][m] << "\n";
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s1[i] == s2[j]){
            ans.push_back(s1[i]);
            i--;
            j--;
        }
        else{
            if(dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    for(int i = ans.size() - 1; i >= 0; i--)
        out << ans[i] << " ";
    return 0;
}
