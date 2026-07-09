
#include <fstream>

using namespace std;

ifstream inf("nim.in");
ofstream outf("nim.out");

int t, n, ok, x;

int main()
{
    inf>>t;
    for(;t;t--)
    {
        inf>>n;
        for(ok=0; n; n--)
            inf>>x,ok^=x;
        ok?outf<<"DA\n":outf<<"NU\n";
    }
    return 0;
}
