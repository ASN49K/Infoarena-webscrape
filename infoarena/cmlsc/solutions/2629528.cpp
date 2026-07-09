#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1025][1025];
int sol[1025];
int main(){
  int i, j, n, m, a[1025], b[1025];
  fin >> n >> m;
  for (i = 1; i<=n; i++)
    fin >> i[a];
  for (i = 1; i<=m; i++)
    fin >> i[b];
  for (i = 1; i<=n; i++)
    for (j = 1; j<=m; j++){
      if (a[i] == b[j])
        dp[i][j] = 1 + dp[i-1][j-1];
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  i = n;
  j = m;
  int k = 0;
  for (;i>0 && j>0;){
    if (a[i] == b[j]){
      k++;
      sol[k] = a[i];
      i--;
      j--;
    }
    else if (dp[i-1][j] > dp[i][j-1])
      i--;
    else
      j--;
  }
  fout << dp[n][m] << '\n';
  for (i = k; i>=1; i--)
    fout << i[sol] << ' ';
  return 0;
}
