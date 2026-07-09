#include <fstream>

using namespace std;

int main()
{
   ifstream f("euclid2.in");
   ofstream g("euclid2.out");
   int n,a,b,x,i,y;
   f>>n;
   for(i=1;i<=n;i++)
   {
       f>>x>>y;
       while(x!=y)
        if(x>y)
        x-=y;
       else
        y-=x;
       g<<x<<'\n';
   }






    return 0;
}
