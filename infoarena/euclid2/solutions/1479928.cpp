#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,a,b,r;
int main()
{
    f>>T;
    for(;T;T--)
    {
        f>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<'\n';
    }
    return 0;
}
