#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a, b, i, n;
int euclid( int a, int b )
{
    int c;
    while( b )
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
  f>>n;
  while(n)
  {
      f>>a>>b;
      g<<euclid(a, b)<<"\n";
      n--;

  }

    return 0;
}
