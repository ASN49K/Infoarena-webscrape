#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
 
int n, a, b;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
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