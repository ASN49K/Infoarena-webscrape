#include <fstream>

std::ifstream cin("euclid2.in");
std::ofstream cout("euclid2.out");

int main() {
  int n, a, b;
  
  cin >> n;
  for (int i {0}; i < n; ++i) {
    cin >> a >> b;
    
    while (b) {
      int r = a % b;
      a = b;
      b = r;
    }
    
    cout << a << "\n";
  }
  
  cin.close();
  cout.close();
  return 0;
}