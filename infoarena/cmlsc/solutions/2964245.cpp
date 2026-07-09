#include <fstream>

using namespace std;
const int N = 1024;

int a[N+1], b[N+1], dp[N+1][N+1], m, n;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void refac_subsir(int l, int c){
    if(l == 0 || c == 0)
        return;

    if(a[l] == b[c]){
        refac_subsir(l - 1, c - 1);
        out << a[l] << ' ';
    }
    else {
        if(dp[l-1][c] > dp[l][c-1])
            refac_subsir(l - 1, c);
        else
            refac_subsir(l, c - 1);
    }
}

int main()
{
    in >> m >> n;

    for(int i = 1; i <= m; i++)
        in >> a[i];

    for(int i = 1; i <= n; i++)
        in >> b[i];

    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int j = 0; j <= m; j++) dp[0][j] = 0;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i] == b[j])dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    out << dp[m][n] << endl;

    refac_subsir(m, n);

    return 0;
}
