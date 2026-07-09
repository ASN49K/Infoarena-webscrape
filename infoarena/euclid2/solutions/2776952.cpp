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
    //printf("%d\n",2+4);
   f>>t;
   for(long int i=0;i<t;i++)
   {
       f>>a>>b;
       printf("%d\n",euclid(a,b));
   }
}
