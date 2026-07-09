#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a, int b)
{
    int rest=0;
    if(a%b==0)
    {
        return b;
    }
    cmmdc(b, a%b);
}
int main ()
{
    int a, b, n;
    f>>n;
    for(int i=1; i<=n;++i)
    {
        f>>a>>b;
        g<<cmmdc(a,b);
    }
}
