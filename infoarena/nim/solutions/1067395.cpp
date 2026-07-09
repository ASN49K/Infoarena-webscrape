#include <fstream>
#define DIM 10000

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t, n, a, xorsum;
    f>>t;

    for(int i = 1; i<=t; i++)
    {
        f>>n;
        xorsum = 0;
        for(int j = 1; j<=n; j++)
        {
            f>>a;
            xorsum ^= a;
        }
        if(xorsum == 0)
        {
            g<<"NU"<<endl;
        }
        else
        {
            g<<"DA"<<endl;
        }
    }
}
