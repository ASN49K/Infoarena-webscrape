#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int const NMAX = 1024;
int dp[1 + NMAX][1 + NMAX];
int a[1 + NMAX];
int b[1 + NMAX];

vector <int> reconstruct;

int main() {

  int n, m;
  in >> n >> m;
  for(int i = 1;i <= n;i++){
    in >> a[i];
  }
  for(int i = 1;i <= m;i++){
    in >> b[i];
  }
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      if(a[i] == b[j]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  out << dp[n][m] << '\n';
  //int oldi = n, oldj = m;
  for(int i = n;i >= 1;i--){
    for(int j = m;j >= 1;j--){
      if(i >= 0 && j >= 0 && a[i] == b[j]){
        reconstruct.push_back(a[i]);
        i--;
      }
    }
  }
  for(int i = reconstruct.size() - 1;i >= 0;i--){
    out << reconstruct[i] << ' ';
  }
  return 0;
}
