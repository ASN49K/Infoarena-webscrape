#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

long euclid(long x, long y)
{
  if(!y)
     return x;
  else
    return euclid(y, x % y);

}

int main()
{
    long a, b, T;

    f>>T;

    while(T)
    {
        f>>a >>b;

        g<<euclid(a,b)<<'\n';

        T--;
    }




    return 0;
}
