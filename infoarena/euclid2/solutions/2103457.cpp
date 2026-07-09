#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,v[200000];

void citire()
{
  f>>n;
  for (int i=1; i<=n*2; i+=2)
    f>>v[i]>>v[i+1];
}

void cmmdc()
{
  for (int i=1; i<=n*2; i+=2)
    {
      int d,p;
      if (v[i]>v[i+1]) d=v[i];
      else d=v[i+1];
      for (int j=1; j<=d; j++)
        {
          if (v[i]%j==0 && v[i+1]%j==0) p=j;
        }
      g<<p<<'\n';
    }
}

int main ()
{
  
  citire();
  cmmdc();
  
  return 0;
}

