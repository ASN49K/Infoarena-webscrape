#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

struct ceva{
    int lungime;
    string subsir;
};

int n, m;
vector<int> s1;
vector<int> s2;
//vector<vector<ceva>> dp;
ceva dp[1025][1025];


int main()
{
    cin >> n >> m;
    s1.resize(n);
    s2.resize(m);
   // dp.resize(n+1);
    //for (int i = 1; i <= m; i++) dp[i].resize(m + 1);
    for (int i = 0; i < n; i++) cin >> s1[i];
    for (int i = 0; i < m; i++) cin >> s2[i];


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j].lungime = dp[i - 1][j - 1].lungime + 1;
                dp[i][j].subsir = dp[i - 1][j - 1].subsir + to_string(s1[i-1]);
            }
            else
            {
                if (dp[i - 1][j].lungime > dp[i][j - 1].lungime)
                {
                    dp[i][j].lungime = dp[i - 1][j].lungime;
                    dp[i][j].subsir = dp[i - 1][j].subsir;

                }
                else
                {
                    dp[i][j].lungime = dp[i][j-1].lungime;
                    dp[i][j].subsir = dp[i][j-1].subsir;
                }
            }
        }
    }
    cout << dp[n][m].lungime << '\n';
    for (int i = 0; i < dp[n][m].subsir.size(); i++) cout << dp[n][m].subsir[i] << " ";
}