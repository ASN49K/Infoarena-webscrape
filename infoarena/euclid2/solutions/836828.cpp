#include <cstdlib>
#include <fstream>

using namespace std;

inline int gcd(int x, int y)
{
    if(y) return gcd(y, x%y);
    return x;
}

int main()
{ 
   int T, x, y;
   ifstream in("euclid2.in");
   ofstream out("euclid2.out");
   
   for(in >> T; T; --T)
   {
       in >> x >> y;
       out << gcd(x, y) << '\n';
   }

   return EXIT_SUCCESS;
}
