#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, k;
int a[1030], b[1030], rez[1030];
int dp[1030][1030];

int main()
{
    in>>n>>m;

    for(int i = 1; i <= n; ++i)
        in>>a[i];

    for(int i = 1; i <= m; ++i)
        in>>b[i];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1]  + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    out<<dp[n][m]<<'\n';


    int i = n, j = m;
    while(i > 0){
        if(a[i] == b[j]){
            rez[++k] = a[i];
            i--; j--;
        }
        else if(dp[i - 1][j] < dp[i][j - 1])j--;
        else i--;
    }

    for(int i = k; i > 0; --i)
        out<<rez[i]<<" ";

    in.close();
    out.close();
    return 0;
}
