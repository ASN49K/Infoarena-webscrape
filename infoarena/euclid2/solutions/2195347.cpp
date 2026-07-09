#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,i,d,j,r;
int main()
{
    f>>t;
    for(j=1;j<=t;j++)
    {
        f>>d>>i;
        r=d%i;
        while(r!=0)
        {
            d=i;
            i=r;
            r=d%i;
        }
        g<<i<<'\n';
    }
    return 0;
}
