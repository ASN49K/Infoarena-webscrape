#include <iostream>
#include <fstream>
using namespace std;
int a,b,i,n;
int cmmdc(int x, int y)
         {

              if (x % y==0) return y;
                     else return cmmdc(x, x % y);

         }
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(max(a,b), min(a,b))<<" ";
    }
    return 0;
}
