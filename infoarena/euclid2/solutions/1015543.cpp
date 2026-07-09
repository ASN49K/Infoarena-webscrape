#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
    r = a % b;
    while(r)
    {
        r = a%b;
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main()
{
   int T, x, y, i;
   f >> T;
   for ( i = 1; i <= T; ++i)
   {
       f >> x >> y;
       g << cmmdc(x, y) << endl;
   }


   return 0;
}
