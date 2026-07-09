#include <fstream>
using namespace std;

int divz(int a,int b)
{
    if(b==0)
        return a;
    return divz(b,a%b);
}


int main()
{
    ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,i,c,d;
   f>>n;
   for(i=1;i<=n;i++)
   {
       f>>c>>d;
      g<<divz(c,d)<<"\n";
   }
   return 0;
}
