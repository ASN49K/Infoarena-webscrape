#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int DIM =1031;

int v1[DIM];
int v2[DIM];
int v3[DIM];

int dp[DIM][DIM];

int main()
{
   ios::sync_with_stdio(false);
   in.tie(0);

   int n ,m;
   in >> n >> m;
   for(int i = 1;i <= n;i++)
    in >> v1[i];
   for(int i = 1;i <= m;i++)
    in >> v2[i];

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
        if(v1[i] == v2[j])
          dp[i][j] = 1 + dp[i-1][j-1];
          else
          dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

    out << dp[n][m] <<"\n";

    int i = n;
    int j = m;
    int p = 0;
    while( i && j)
    {
        if(v1[i] == v2[j])
        {
         v3[++p] = v1[i];
         i--;
         j--;
        }
        else
        if(dp[i][j-1] > dp[i-1][j])
        j--;
        else
        i--;
    }
    for(int i = p;i >= 1;i--)
        out << v3[i] << " ";
    return 0;
}
