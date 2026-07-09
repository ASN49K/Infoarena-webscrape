#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
  int n, a, b, d;
  fin >> n;
  
  for (int i=1; i<=n; i++){
    fin >> a >> b;
    while (a % b != 0){
      d = a % b;
      a = b;
      b = d;
    }
    fout << b << '\n';
  }
  
  return 0;
}
