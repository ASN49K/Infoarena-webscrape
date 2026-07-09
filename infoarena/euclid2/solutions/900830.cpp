#include <fstream>
using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int n, x, y;

int euclid2 (int a, int b)
{
    if (a%b==0)
        return b;
    else return euclid2 (b,a%b);
}

int euclid1 (int a, int b)
{
    if (a>=b)
        return euclid2 (a,b);
    else return euclid2 (b,a);
}

int main()
{
    f>>n;
    for (int i=1; i<=n; ++i)
    {
        f>>x>>y;
        g<<euclid1(x,y)<<'\n';
    }
    return 0;
}


