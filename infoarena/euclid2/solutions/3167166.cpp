#include <iostream>
#include <fstream>
using namespace std;

int euclid(int a, int b)
{
  if (!b) return a;
  return euclid(b, a%b);
}

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
  int n, a, b;
  fin >> n;
  while (fin >> a >> b)
  {
    fout << euclid(a, b) << endl;
  }
  return 0;
}