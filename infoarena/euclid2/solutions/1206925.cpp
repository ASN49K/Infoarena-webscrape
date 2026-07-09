#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long n,aux,a,b,r,j;
int main()
{
  f>>n;
  for(j=1;j<=n;j++)
  {
   f>>a>>b;
   if(a<b)
   {
    aux=b;
    b=a;
    a=aux;
   }
   r=a%b;
   while(r)
   {
     a=b;
     b=r;
     r=a%b;
   }
    g<<b<<'\n';
  }
  f.close();
  g.close();
  return 0;
}
