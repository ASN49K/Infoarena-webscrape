#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n,x,v;
int main()
{
    f>>t;
    for(;t;t--)
    {
        f>>n;
        v=0;
        for(;n;n--)
        {
            f>>x;
            v^=x;
        }
        if(v)g<<"DA\n";
        else g<<"NU\n";
    }
    return 0;
}
