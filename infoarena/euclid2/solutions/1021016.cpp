#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out")
  int T, A, B;
   int gcd(int a, int b)
   {
            if (!b) return a;
                 return gcd(b, a % b);
                  }
                     int main(void)
                      {
                               f>>T;
                               int n;
                               for(; T; --T)
                                {
                                    f>>A>>B;
                                    n=gcd(A, B);
                               g<<'\n'<<n<<'\n';
                                    }
                               return 0;
                                }
