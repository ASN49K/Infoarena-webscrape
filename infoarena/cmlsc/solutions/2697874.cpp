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

vector <int> output;

void reconstruct(int i, int j){
  if(i == 0 || j == 0){
    return;
  }else if(a[i] == b[j]){
    reconstruct(i - 1, j - 1);
    output.push_back(a[i]);
  }else{
    if(dp[i-1][j] > dp[i][j-1]){
      reconstruct(i - 1, j);
    }else{
      reconstruct(i, j - 1);
    }
  }
}

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
  reconstruct(n, m);
  for(int i = 0;i < output.size();i++){
    out << output[i] << ' ';
  }
  return 0;
}

