#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n,r,x;
int main()
{
    f>>t;
    for(;t;t--)
    {
        f>>n;
        r=0;
        for(;n;n--)
        {
            f>>x;
            r^=x;
        }
        if(r==0)
            g<<"NU\n";
        else
            g<<"DA\n";
    }
    return 0;
}
