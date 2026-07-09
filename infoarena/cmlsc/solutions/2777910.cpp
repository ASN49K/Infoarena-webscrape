#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int NMAX = 1030;
int  dr[NMAX], dp[NMAX][NMAX];
int main()
{
    int a[NMAX], b[NMAX], m, n;

    in >> m >> n;
    for(int i = 1;i <= m;i ++)
    {
        in >> a[i];
    }
    for(int j = 1;j <= n;j ++)
    {
        in >> b[j];
    }

   int k = 0;
   for(int i = 1;i <= m;i ++)
    for(int j = 1;j <= n;j ++)
   {
       if(a[i] == b[j])
       {
           dp[i][j] = dp[i - 1][j - 1] + 1;
           dr[k ++] = a[i];
       }
       else{
        dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
       }
   }

    out << dp[m][n] << "\n";
    for(int i = 0;i < k;i ++)
        out << dr[i] <<" ";

    return 0;
}
