#include <fstream>

using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int main()
{
   int i , t , a , r , b;
   f>>t;
   for(i=1;i<=t;i++)
   {
       f>>a>>b;
       while(b)
       {
           r=a%b;
           a=b;
           b=r;
       }
       g<<a<<" ";
   }
   f.close();
   g.close();
}
