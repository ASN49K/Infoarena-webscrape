#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,i,x,y,r;
int main()
{
   f>>t;
   for(i=1;i<=t;i++)
   {
       f>>x>>y;
       r=x%y;
       while(r>0)
       {
           x=y;y=r;r=x%y;
       }
       g<<y<<'\n';
   }

}
