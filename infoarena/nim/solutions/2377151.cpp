#include <fstream>
using namespace std;
int t, n, a, xorsum;
int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");
    f>>t;
    while(t--)
    {
        f>>n;
        xorsum = 0;
        for(int i = 1; i <= n; ++i)
        {
            f>>a;
            xorsum = xorsum ^ a;
        }
        if(xorsum)
            g<<"DA\n";
        else
            g<<"NU\n";
    }
    return 0;
}
