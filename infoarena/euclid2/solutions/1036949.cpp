#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
   int a,b,T,r;
   f>>n;
   for(int i=1;i<=T;i++)
   {
       f>>a>>b;
       while(b!=0)
       {
           r=a%b;
           a=b;
           b=r;
       }
     g<<a<<" "<<"\n";
   }

    return 0;
}
