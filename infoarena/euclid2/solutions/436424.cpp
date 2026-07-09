#include<fstream.h>


int main()
{
  ifstream f("euclid2.in");ofstream g("euclid2.out");
  int rest,a,b;
  f>>a;
  while(f>>a>>b)
  {
    while(b){rest=a%b;a=b;b=rest;}
    g<<a<<'\n';
  }
  f.close();
  g.close();
  return 0;
}