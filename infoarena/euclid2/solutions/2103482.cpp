#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
  if (!b) return a;
  else return cmmdc(b,a%b);
}

int a,b,n;

int main ()
{
  f>>n;
  for (int i=1; i<=n; i++)
    { 
      f>>a>>b;
     g<<cmmdc(a,b)<<'\n';
    }
  return 0;
}