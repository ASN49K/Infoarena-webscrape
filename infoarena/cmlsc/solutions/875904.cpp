#include <fstream>
#include <math.h>
#define m 1999999973

using namespace std;

ifstream f("lgput.in");
ofstream g("lgput.out");
long long n,p,i,r,a;
long long putere(long long int x,long long y)
{
  a=1;
while(p>0)
    if(p%2==0)
    {
        n=(n*n);
        p=p/2;
    }
    else
    {
        a=(a*n);
        p--;
    }
  return a;
}

int main()
{

    f>>n>>p;
   g<<putere(n,p);
    return 0;
}
