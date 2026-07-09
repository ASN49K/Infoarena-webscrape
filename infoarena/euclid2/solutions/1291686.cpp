#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,r;
int main()
{
    f>>t;
    for(;t;t--)
    {
        f>>a>>b;
        for(;b;)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<'\n';
    }
    return 0;
}
