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
  int i = a.size(), j = b.size();
  while(i > 0 && j > 0){
    if(a[i-1] == b[j-1]){
      aux.push_back(a[i-1]);
      i--;
      j--;
    }
    else{
      if(dp[i-1][j] > dp[i][j-1]){
        i--;
      }
      else{
        j--;
      }
    }
  }
  return dp[a.size()][b.size()];
}

int main(){
  
  int n, m;
  fin >> n >> m;
  std::vector<int> a(n);
  std::vector<int> b(m);

  for(int i = 0; i<n; i++){
    fin >> a[i];
  }
  for(int i = 0; i<m; i++){
    fin >> b[i];
  } 
  std::vector<int> aux;
  fout << lcs(a, b, aux) << std::endl;
  std::reverse(aux.begin(), aux.end());
  for(auto it : aux) fout << it << " ";
}

