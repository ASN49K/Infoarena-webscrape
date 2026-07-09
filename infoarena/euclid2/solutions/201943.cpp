#include <iostream>
#include <fstream>
// Adunare

using namespace std;

int main()
{
long a,b,n,t;

      ifstream f ("euclid2.in");
      ofstream g("euclid2.out");
      f>>n;
      for (long i=1; i<=n; i++)
        {
          f>>a>>b;
          while (b != 0)
          {
                t = b;
                b = a % b;
                a = t;
                }      
          g<<a<<"\n";      
          }
      f.close();
      g.close();
      

      return 0;
      }
