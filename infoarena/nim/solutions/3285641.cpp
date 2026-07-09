#include <iostream>

using namespace std;

int const NMAX = 100;

int main() {

  int t;
  cin >> t;
  for(int q = 1;q <= t;q++) {
    int n, ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) {
      int c;
      cin >> c;
      ans ^= c;
    }
    if(ans == 0) {
      cout << "NU\n";
    }else {
      cout << "DA\n";
    }
  }
  cout << '\n';
  return 0;
}
