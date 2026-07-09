#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void print(const vector<int>& x, const vector<int>& y,
           const vector<vector<int>>& dp,
           const int& i, const int& j) {
  if (i == 0 || j == 0) {
    return;
  }
  if (x[i-1] == y[j-1]) {
    print(x, y, dp, i-1, j-1);
    out<<x[i-1]<< " ";
  } else {
    if (dp[i-1][j] > dp[i][j-1]) {
      print(x, y, dp, i-1, j);
    } else {
      print(x, y, dp, i, j-1);
    }
  }
}

void cmlsc(const vector<int>& x, const vector<int>& y) {
  vector<vector<int>> dp;
  dp.resize(x.size() + 1);
  for (int i = 0; i <= x.size(); ++i) {
    dp[i].resize(y.size() + 1);
  }
  for (int i = 0; i <= x.size(); ++i) {
    for (int j = 0; j <= y.size(); ++j) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
        continue;
      }
      if (x[i-1] == y[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
      }
    }
  }
  out << dp[x.size()][y.size()] << "\n";
  print(x, y, dp, x.size(), y.size());
}

int main (int argc, char const *argv[]) {
  int x_len, y_len;
  in>>x_len>>y_len;
  vector<int> x(x_len, 0);
  vector<int> y(y_len, 0);
  for (int i = 0; i < x_len; ++i) {
    in>>x[i];
  }
  for (int i = 0; i < y_len; ++i) {
    in>>y[i];
  }
  cmlsc(x, y);
  return 0;
}
