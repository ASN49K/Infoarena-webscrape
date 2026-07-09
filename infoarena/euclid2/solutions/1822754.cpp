#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,d,i,T,r;
int main()
{
   f>>T;
   for(i=1;i<=T;i++)
   {f>>a>>b;

   while(b!=0)
   {
   r=a%b;
   a=b;
   b=r;
   }
   d=a;
   g<<d<<'\n';
   }


    return 0;
}
