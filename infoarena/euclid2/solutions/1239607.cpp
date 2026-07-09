#include <fstream>

using namespace std;
long t,i,a,b;
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for (i=1;i<=t;i++)
{
    f>>a>>b;
    while (a != b) {
    if (a > b)
      a -= b;
    else
      b -= a;
  }
  g<<a<<endl;
}
    return 0;;
}
