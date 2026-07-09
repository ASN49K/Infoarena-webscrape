#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g ("euclid2.out");

int gcd(int m, int n)
{
    if (n==0) return m;
    return gcd(n,m%n);
}
int main()
{
    int t,i,m,n;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>m>>n;
        g<<gcd(m,n)<<'\n';
    }

    return 0;
}
