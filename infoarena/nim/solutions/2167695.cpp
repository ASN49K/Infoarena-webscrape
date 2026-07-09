#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t,n,a,nims;

int main()
{
     f>>t;
     int i,j;
     for(i=1;i<=t;i++)
     {
         f>>n;
         nims = 0;
         for(j=1;j<=n;j++)
         {
             f>>a;
             nims ^= a;
         }

     if(nims == 0)
        g<<"NU";
            else
        g<<"DA" ;
        g<<"\n";
     }

}
