#include <iostream>
#include <fstream>
using namespace std;
long long a,b,i,n;
int cmmdc(long long  x, long long y)
         {

              if (y==0) return x;
             return cmmdc(y, x % y);

         }
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
