#include <fstream>
#include <iostream>
#include <algorithm>
#include <utility>
#define f first
#define s second
#define inf 2000000000
using namespace std;
int n, i, a, b, r;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
  fin >> n;
   for (i = 1; i <= n; ++i)
     {
         fin >> a >> b;

         while (r != 0)
             {
             r = a % b;
             a = b;
             b = r;
             }

         fout << a << '\n';

     }

    return 0;
}
