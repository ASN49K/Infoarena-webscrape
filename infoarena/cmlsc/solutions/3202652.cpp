#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("palindrom.in");
ofstream fout("palindrom.out");
const int NMAX = 2001;
int n, dp[NMAX][NMAX], sol;
char s[NMAX];

int main()
{
    fin >> s;
    n = strlen(s);
    for(int i = 0; i < n; i++) dp[i][i] = 1;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(s[i] == s[j] && i != j) dp[i][j] = 2;
    for(int k = 3; k <= n; k++){
        for(int i = 0; i < n - k + 1; i++){
            int j = i + k - 1;
            if(s[i] == s[j]) dp[i][j] = max(dp[i + 1][j - 1] + 2, dp[i][j]);
            else dp[i][j] = max(dp[i + 1][j - 1], dp[i][j]);
            sol = max(sol, dp[i][j]);
        }
    }
    fout << sol;
    return 0;
}
