#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  ifstream fin("euclid2.in");
  ofstream fout("euclid2.out");

  int i, n;
  fin >> n;

  for (i = 0; i < n; ++i) {
    int a, b, r;
    fin >> a >> b;

    do {
      r = a % b;
      a = b;
      b = r;
    } while (r != 0);

    fout << a << endl;
  }

  return 0;
}
