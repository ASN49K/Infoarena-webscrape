#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int t,r,a,b;
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>a>>b;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    g<<a<<'\n';
    }
    return 0;
}
