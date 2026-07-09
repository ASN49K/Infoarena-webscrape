#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b,r;
int main()
{
   f>>n;
   for(;n;n--)
   {
       f>>a>>b;
       while(b)
       {
           r=a%b;
           a=b;
           b=r;
       }
       g<<a<<'\n';
   }

    return 0;
}
