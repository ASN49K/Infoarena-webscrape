#include <fstream>
using namespace std;
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int nr,a,b,aux,i;
f>>nr;
for (i=1;i<=nr;i++)
{
  f>>a>>b;
  if (b>a) {
    aux = a;
    a = b;
    b = aux;
  }
  while (a)
  {
    aux = b%a;
    b = a;
    a = aux;
  }
  g<< b <<'\n';
}
}
