#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int NMAX = 1024;
int a[NMAX + 1], b[NMAX + 1];
int n, m;

int dp[NMAX + 1][NMAX + 1];
int f1[257],f2[257];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    
    int lmax = dp[n][m];
    
    for(int i = 1; i <= n; i++)
        f1[a[i]]++;
    for(int i = 1; i <= m; i++)
        f2[b[i]]++;

    cout << lmax << '\n';
    for(int i = 0; i <= 256 && lmax != 0; i++)
        if(f1[i] && f2[i])
            cout << i << ' ', lmax--;



    return 0;
}