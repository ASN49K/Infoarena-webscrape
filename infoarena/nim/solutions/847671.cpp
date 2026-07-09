#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t,n,xorsum,x;

int main()
{
    int i;
    for(f>>t;t;--t)
    {
        f>>n;
        xorsum=0;
        for(i=1;i<=n;++i)
        {
            f>>x;
            xorsum = xorsum ^ x;
        }
        if(xorsum!=0) g<<"DA\n";
        else g<<"NU\n";
    }
    f.close(); g.close();
    return 0;
}
