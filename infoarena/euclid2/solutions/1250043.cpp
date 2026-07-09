#include <fstream>

using namespace std;
ifstream f("euclid2.in");
    ofstream g("euclid2.out");
long x,y;
long CMMDC(long a, long b)
  {

   long t;
    while (b != 0)
        {t = b;
       b = a % b;
       a = t;}
    return a;


    }
int main()
{  while (f>>x>>y)
    g << CMMDC(x,y) << endl;
    return 0;
}
