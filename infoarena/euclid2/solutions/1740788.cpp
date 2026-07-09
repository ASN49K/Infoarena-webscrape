#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int a,b,r;
    f>>a>>b;
    f.close();
    r=a%b;
    while (r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    g<<b;
    g.close();
    return 0;
}
