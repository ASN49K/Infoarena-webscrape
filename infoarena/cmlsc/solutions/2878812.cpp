#include <fstream>
#include <stack>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define DIM 1024

int n, m;
int a[DIM + 1], b[DIM + 1];
int dp[DIM + 1][DIM + 1];
stack <int> ans;

static inline void SubsirComMax() {
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      if(a[i] == b[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  
  int l = n, c = m;
  while(l && c) 
    if(a[l] == b[c]) {
      ans.push(a[l]);
      l--;
      c--;
    }else if(dp[l][c] == dp[l - 1][c])
      l--;
    else c--;
}

int main() {
  fin >> n >> m;

  for(int i = 1; i <= n; i++)
    fin >> a[i];
  for(int i = 1; i <= m; i++)
    fin >> b[i];

  SubsirComMax();

  fout << ans.size() << '\n';
  while(!ans.empty()) {
    fout << ans.top() << " ";
    ans.pop();
  }

  return 0;
}