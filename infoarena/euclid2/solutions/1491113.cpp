#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,x,y;

int gcd(int x,int y)
{
    if (y==0) return x;
    return gcd(y,x%y) ;
}

int main()
{
    f>>n;
    for (int i=1; i<=n; ++i)
    {
        f>>x>>y;
        g<<gcd(x,y)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
