#include <fstream>
#include <algorithm>
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
         fout << __gcd(a,b) << '\n';
     }

    return 0;
}
