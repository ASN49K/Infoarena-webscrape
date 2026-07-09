#include <fstream>
using namespace std;

void euclid(int a, int b, int *d)
{
    if (b == 0)
    {
        *d = a;
    }
    else
        euclid(b, a % b, d);
}

int main(void)
{
    int a,b,t,d;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for (;t;t--)
    {
        f>>a>>b;
        euclid(a,b,&d);
        g<<d<<"\n";
    }
    f.close();
    g.close();
}
