#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int lcs(const std::vector<int> &a,
        const std::vector<int> &b,
        std::vector<int> &aux
        ){
  std::vector<std::vector<int> > dp(a.size() + 1, std::vector<int>(b.size() + 1, 0));
  for(int i = 1; i <= a.size(); i++){
    for(int j = 1; j <= b.size(); j++){
      if(a[i-1] == b[j-1]){
        dp[i][j] = 1 + dp[i-1][j-1];
      }
      else
        dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
    }
  }
  int tmp = 0;
   for(int i = 1; i<=a.size(); i++){
      if(dp[i][b.size()] > tmp){
        aux.push_back(a[i-1]);
        tmp = dp[i][b.size()];
      }
    }
    return dp[a.size()][b.size()];
}

int main(){
  std::vector<int> a;
  std::vector<int> b;

  int n, m;
  fin >> n >> m;
  for(int i = 0; i<n; i++){
    int x;
    fin >> x;
    a.push_back(x);
  }
  for(int i = 0; i<m; i++){
   int x;
   fin >> x;
   b.push_back(x);
  } 
  std::vector<int> aux;
  fout << lcs(a, b, aux) << std::endl;
  for(auto it : aux) fout << it << " ";
}

