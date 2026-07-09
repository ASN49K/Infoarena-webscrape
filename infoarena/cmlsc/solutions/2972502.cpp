#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");



const int N = 1025;
int dp[N][N];
int a[N], b[N];
vector<int> lcs_seq;

void print_lcs(int m, int n) {
  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (a[i-1] == b[j-1]) {
      lcs_seq.push_back(a[i-1]);
      i--; j--;
    } else if (dp[i-1][j] > dp[i][j-1]) {
      i--;
    } else {
      j--;
    }
  }
  reverse(lcs_seq.begin(), lcs_seq.end());
}

int lcs(int m, int n) {
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i-1] == b[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  print_lcs(m,n);
  return dp[m][n];
}

int main() {
  int m, n;
  fin >> m >> n;
  for (int i = 0; i < m; i++) fin >> a[i];
  for (int i = 0; i < n; i++) fin >> b[i];
  fout << lcs(m, n) << endl;
  for(int i=0;i<lcs_seq.size();i++)
    fout<<lcs_seq[i]<<" ";
  return 0;
}
