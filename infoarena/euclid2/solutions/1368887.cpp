#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int k,a,b,t,i;
int main()
{
    f>>k;
    for(i=1;i<=k;i++)
    {
        f>>a>>b;
        while(b!=0)
        {
          t=a%b;
          a=b;
          b=t;
        }
        g<<a<<"\n";
    }
    return 0;
}
