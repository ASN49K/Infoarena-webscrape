#include <fstream>
#include <algorithm>
#define MAX_NM 1025
using namespace std;

int n, m, sn[MAX_NM], sm[MAX_NM], dp[MAX_NM][MAX_NM];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void read()
{
  fin>>n>>m;
  for(int i=1; i<=n; ++i)
    fin>>sn[i];
  for(int i=1; i<=m; ++i)
    fin>>sm[i];
}

void solve()
{
  for(int i=n; i; --i)
    for(int j=m; j; --j)
      dp[i][j] = sn[i] == sm[j] ? 1 + dp[i+1][j+1] : max(dp[i+1][j], dp[i][j+1]);
}

inline bool is_legal(int l, int c)
{
  return (l<=n && c<=m);
}

void print_sol(int l, int c)
{
  if(is_legal(l, c))
  {
    if(sn[l] == sm[c])
    {
      fout<<sn[l]<<" ";
      print_sol(l+1, c+1);
    }
    else if(!is_legal(l+1, c) || (is_legal(l, c+1) && dp[l+1][c]<=dp[l][c+1]))
      print_sol(l, c+1);
    else
      print_sol(l+1, c);
  }
}

void print()
{
  fout<<dp[1][1]<<"\n";
  print_sol(1, 1);
}

int main()
{
  read();
  solve();
  print();

  return 0;
}
