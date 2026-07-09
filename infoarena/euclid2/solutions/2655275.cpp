#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main() {
  int n, a, b;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    while (a != b) {
      if (a > b) a -= b;
      else if (a < b) b -= a;
    }
    cout << a << endl;
  }
  return 0;
}