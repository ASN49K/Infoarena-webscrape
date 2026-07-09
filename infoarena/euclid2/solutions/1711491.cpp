#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r,n;
int main()
{   f>>n;
    while(n--)
    {f>>a>>b;
      while(b)
      { r=a%b;
        a=b;
        b=r;
      }
        g<<a<<endl<<n;
    }
g.close(); return 0;
}
