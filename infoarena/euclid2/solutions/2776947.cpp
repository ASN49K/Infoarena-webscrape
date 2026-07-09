#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long int euclid(long int a,long int b)
{
    if(!a) return b;
    return euclid(b%a,a);
}
int main()
{
    long int t,a,b;
   f>>t;
   for(long int i=0;i<t;i++)
   {
       f>>a>>b;
       g<<euclid(a,b)<<endl;
   }
}
