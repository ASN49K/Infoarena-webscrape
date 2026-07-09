#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n;
long long v[200000];

void citire()
{
  f>>n;
  for (int i=1; i<=n*2; i+=2)
    f>>v[i]>>v[i+1];
}

int cmmdc(int a,  int b)
{
  if(!b) return a;
  return cmmdc(b,a%b);
}

void scriere()
{
  for (int i=1; i<=n*2; i+=2)
        g<<cmmdc(v[i],v[i+1])<<'\n';
}

int main ()
{
  
  citire();
  scriere();
  
  return 0;
}