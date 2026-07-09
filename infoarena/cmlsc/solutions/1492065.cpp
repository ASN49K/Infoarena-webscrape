#include <fstream>
#include <vector>

using namespace std;

template<class DataType> 
vector<DataType> lcs(
    const vector<DataType>& a, const vector<DataType>& b) {
  
  vector< vector<int> > dp(a.size() + 1, vector<int>(b.size() + 1));
  for (size_t i = 1; i <= a.size(); i++) {
    for (size_t j = 1; j <= b.size(); j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  int i = (int)a.size();
  int j = (int)b.size();
  int k = dp[i][j];
  vector<DataType> ret(k);
  while (i > 0 && j > 0) {
    if (a[i - 1] == b[j - 1]) {
      i--, j--;
      ret[--k] = a[i];
    } else 
    if (dp[i][j - 1] > dp[i - 1][j]) {
      j--;
    } else {
      i--;
    }
  } 
  return ret;
}

int main() {
  ifstream cin("cmlsc.in");
  ofstream cout("cmlsc.out");
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  vector<int> c = lcs<int>(a, b);
  cout << c.size() << "\n";
  for (auto& x : c) {
    cout << x << " ";
  }
}
