#include <fstream>
const int NMAX=1030;

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[NMAX][NMAX], s[NMAX], t[NMAX];
pair <int, int> mm[NMAX][NMAX];
int n, m;

void merg(int, int);

int main()
{
  int i, j;
  fin>>n>>m;
  for(i=1; i<=n; i++) fin>>s[i];
  for(i=1; i<=m; i++) fin>>t[i];
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=m; j++)
    {
      if(s[i]==t[j])
      {
        dp[i][j]=dp[i-1][j-1]+1;
        mm[i][j]=make_pair(i-1, j-1);
      }
      else
      {
        dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        if(dp[i-1][j]==dp[i][j]) mm[i][j]=make_pair(i-1, j);
        else mm[i][j]=make_pair(i, j-1);
      }
    }
  }
  fout<<dp[n][m]<<'\n';
  merg(n, m);
}

void merg(int n, int m)
{
  if(n==0 || m==0) return;
  merg(mm[n][m].first, mm[n][m].second);
  if(s[n]==t[m]) fout<<s[n]<<' ';
}
