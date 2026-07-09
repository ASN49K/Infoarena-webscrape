#include <fstream>
using namespace std;
int a, b, c, T, r, i;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for (i=1; i<=T; i++)
    {
        f>>a>>b;
        while (b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<"\n";
    }
    return 0;
}
