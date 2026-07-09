#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
   int t;
   fin >> t;
   for (int i = 1; i <= t; i++)
   {
      int a, b;
      fin >> a >> b;
      while (a > 0 and b > 0)
      {
         if (a > b)
            a = a % b;
         else
            b = b % a;

      }
      fout << max(a, b) << '\n';
   }
   fin.close();
   fout.close();
   return 0;
}
