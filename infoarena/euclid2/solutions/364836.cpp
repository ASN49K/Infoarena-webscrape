#include <fstream.h>
int x;

int cmmd(int a,int b)
{
  if(b==0)
    return a;
  else
    return cmmd(b,a%b);
}

int main()
{
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  long a,b;
  f>>x;
  for(int i=1;i<=x;i++)
    {
      f>>a>>b;
      g<<cmmd(a,b)<<'\n';
    }
  g.close();
  return 0;
}