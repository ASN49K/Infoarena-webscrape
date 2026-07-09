#include <fstream>
using namespace std;

int cmmdc(int x, int y)
{
    if (y == 0)
        return x;
    else
        return cmmdc(y, x % y);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,n2,t;
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>n>>n2;
        g<<cmmdc(n,n2);
        g<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
