#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a,int b)
{
   int r;
   while(b)
   {
       r=a%b;
       a=b;
       b=r;
   }
   return a;
}

int amax,insule,a,b,i,j,n,m;
int main()
{
    f>>n;
    for(i=1; i<=n; i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;

    }

    return 0;
}
