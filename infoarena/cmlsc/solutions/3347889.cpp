#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int mxN = 1025;

int n, m, a[mxN], b[mxN], ans[mxN], dp[mxN][mxN];

int main(){
    int indI, indJ, len;
    fin >> n >> m;
    indI = n, indJ = m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }

    fout << dp[n][m] << "\n";

    len = dp[n][m];

    while(indI > 0 && indJ > 0){
        if(a[indI] == b[indJ]){
            ans[len--] = a[indI];
            indI--, indJ--;
        }else if(dp[indI - 1][indJ] > dp[indI][indJ - 1])
            indI--;
        else
            indJ--;
    }

    for(int i = 1; i <= dp[n][m]; i++)
        fout << ans[i] << " ";
}