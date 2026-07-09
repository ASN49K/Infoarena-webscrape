#include <fstream>

using namespace std;

int _gcd (int a, int b){
  if (!b)
    return a;
  return _gcd(b, a % b);
}

int main(){

  ifstream fin ("euclid2.in");
  ofstream fout ("euclid2.out");

  int n;
  fin >> n;
  for (int i = 1; i <= n; i++){
    int a, b;
    fin >> a >> b;
    fout << _gcd(a, b) << "\n";
  }
  return 0;
}
