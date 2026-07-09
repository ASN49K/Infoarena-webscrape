#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n;
unsigned long long a,b;

unsigned long long cmmdc(unsigned long long a, unsigned long long b)
{
    while (a!=b)
    {
        if (a>b) a=a-b;
        else b=b-a;
    }
    return a;
}

int main()
{
    f>>n;
    for (int i=1; i<=n; ++i)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
