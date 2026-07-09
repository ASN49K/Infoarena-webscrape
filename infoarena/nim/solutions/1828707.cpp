#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n,x,ok;
int main()
{
    f>>t;
    for(;t;t--)
    {
        f>>n;
        for(ok=0;n;n--)
        {
            f>>x;
            ok^=x;
        }
        ok?g<<"DA\n":g<<"NU\n";
    }
    return 0;
}
