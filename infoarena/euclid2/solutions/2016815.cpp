#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int t, i, r, d, j;

int main()  {
  fin >> t;
  for (j = 1; j <= t; j++)  {
    fin >> d >> i;
    do  {
      r = d % i;
      d = i; i = r;
    } while (i);
    fout << d << '\n';
  }
}
