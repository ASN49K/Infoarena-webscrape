#include <fstream>
#include <cstdlib>

using namespace std;

/**
 * x = 9   y = 10
 * x = 10  y = 9
 * x = 9   y = 1
 * x = 1   y = 
 **/

inline int gcd(int x, int y)
{
  if(!y) return x;
  return gcd(y, x % y);
}

int main()
{
  int T, a, b;
  ifstream in("euclid2.in");
  ofstream out("euclid2.out");

  for(in >> T; T; --T)
  {
     in >> a >> b;
     out << gcd(a, b) << '\n'; 
  }

  return EXIT_SUCCESS;
}
