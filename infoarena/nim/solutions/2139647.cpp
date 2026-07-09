#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int n,k,r,xorsum;
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>k;
        xorsum=0;
        for(int j=1;j<=k;j++)
        {
            f>>r;
            xorsum=xorsum^r;
        }
        if(xorsum)
        g<<"DA"<<'\n';
        else
        g<<"NU"<<'\n';
    }
    return 0;
}
