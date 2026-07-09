// https://www.infoarena.ro/problema/euclid2
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, a, b;

int cgd(int a, int b)
{
  while (b != 0)
  {
    int tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

int main()
{
  fin >> T;

  for (int i = 0; i < T; i++)
  {
    fin >> a >> b;
    fout << cgd(a, b) << endl;
  }

  return 0;
}