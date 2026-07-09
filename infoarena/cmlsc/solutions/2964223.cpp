#include <fstream>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int m, n, a[1025], b[1025], subsir[1025], dp[1026][1026];

int main()
{
  cin >> m >> n;
  for(int i = 1; i <= m; i++)
  {
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++)
  {
    cin >> b[i];
  }
  cin.close();
  for(int i = 1; i <= m; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      if(a[i] == b[j])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << dp[m][n] << '\n';

  int i = m, j = n, k = 0;
  for(; i; )
  {
    if(a[i] == b[j])
    {
      subsir[++k] = a[i];
      --i;
      --j;
    }
    else if(dp[i - 1][j] < dp[i][j - 1])
    {
      --j;
    }
    else
    {
      --i;
    }
  }

  for(i = k; i >= 1; i--)
  {
    cout << subsir[i] << ' ';
  }
  cout << '\n';
  cout.close();
  return 0;
}
