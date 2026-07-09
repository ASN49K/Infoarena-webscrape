#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, v1[1034], v2[1034], dp[1034][1034], sol[1034], l;

int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++) fin >> v1[i];
    for(int i = 1; i <= m; i++) fin >> v2[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(v1[i] == v2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    fout << dp[n][m] << endl;
    for(int i = n, j = m; i; ){
        if(v1[i] == v2[j]) sol[l++] = v1[i], i--, j--;
        else if(dp[i][j - 1] > dp[i - 1][j]) j--;
        else i--;
    }
    for(int i = l - 1; i >= 0; i--) fout << sol[i] << ' ';
    return 0;
}