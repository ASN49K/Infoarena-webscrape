#include <iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a, int b)
{
    if (b == 0) return a;
     else
      return euclid(b, a % b);
}
int main()
{int T,x,y;
f>>T;
for(int i=0;i<T;i++)
   {
       f>>x>>y;
    g<<euclid(x,y)<<'\n';
   }
    return 0;
}
