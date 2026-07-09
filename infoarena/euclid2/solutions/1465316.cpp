#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t, a, b, i;
int div (int x, int y)
{
    while (y)
    {
        x=y;
        y=x%y;
    }
    return x;
}
int main()
{
    f>>t;
    for(i=1; i<=t; i++)
    {   f>>a>>b;
        g<<div(a, b)<<"\n";
    }
    return 0;
}
