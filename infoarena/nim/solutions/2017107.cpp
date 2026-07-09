#include <iostream>
#include <fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int t, n;
int xxor;

int main()
{
  in >> t;
  for(int i = 1; i <= t; i++) {
    in >> n;
    xxor = 0;
    for(int j = 1; j <= n; j++) {
      int x;
      in >> x;
      xxor ^= x;
    }

    if(xxor == 0) {
      out << "NU\n";
    } else {
      out << "DA\n";
    }
  }
  return 0;
}
