#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

// lungimea subsirului comun crescator de lungime maxima
int main() {

  int s[1026];
  int t[1026];
  int n, m;

  int dp[1026][1026];

  in>>n>>m;

  for (int i = 1; i <= n; i++) {
    in>>s[i];
  }

  for (int i = 1; i <= m; i++) {
    in>>t[i];
  }

  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= m; j++) {
    dp[0][j] = 0;
  }

  // dp[i][j] lunasldlasjdlkajsldkgimea maxima a subsirului comul al sirului s[i] si t[j]
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int eq = (s[i] == t[j]);
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      dp[i][j] = max(dp[i][j], eq + dp[i - 1][j - 1]); 
    }
  }
 
  out<<dp[n][m]<<"\n";

  int temp = dp[n][m];
  // reconstituirea solutiei
  int lastJ = m;
  stack<int> sol;
  for (int i = n; i >= 1; i--) {
    for (int j = lastJ; j >= 1; j--) {
      if(dp[i][j] == temp && s[i] == t[j]) {
        sol.push(s[i]);
        temp--;
        lastJ = j - 1;
        break;
      }
    }
  }

  while(!sol.empty()) {
    out<<sol.top()<<" ";
    sol.pop();
  }

  return 0;
}