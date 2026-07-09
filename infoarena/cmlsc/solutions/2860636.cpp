#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, a[1025], b[1025], dp[1025][1025], l, s[1025];

int main()
{
    fin >> m >> n;
    for(int i=1; i<=m; i++)
        fin >> a[i];
    for(int i=1; i<=n; i++)
        fin >> b[i];
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i] != b[j])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            else
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    fout << dp[m][n] << '\n';
    int i = m, j = n;
    while(i!=0 && j!=0){
        if(a[i] == b[j]){
            l++;
            s[l] = a[i];
            i--;
            j--;
        }
        else
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
    }
    for(int i=l; i>=1; i--)
        fout << s[i] << ' ';
    return 0;
}
