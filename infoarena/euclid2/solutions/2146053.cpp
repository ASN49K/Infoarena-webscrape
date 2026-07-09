#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    long long n,a,b,c,i;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        c=__gcd(a,b);
        g<<c<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
