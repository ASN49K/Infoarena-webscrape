#include<iostream>
#include<fstream>
using namespace std;
ifstream fin  ("euclid2.in");
ofstream fout ("euclid2.out");
int main ()
{
  int i, T, x, y, r;
  fin >> T;
  for (int i=1; i<=T; i++)
  {
    fin >> x >> y;
    while (y!=0)
    {
       r = x%y;
       x = y;
       y = r;
    }
    fout << x << "\n";
  }
  fin.close();
  fout.close();
  return 0;
}
