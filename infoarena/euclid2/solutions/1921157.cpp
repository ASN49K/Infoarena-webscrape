#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b;
int bla(int a, int b)
{
    if (!b) return a;
    return bla(b, a % b);
}

int main(void)
{
    f>>t;
    for (;t;t--) f>>a>>b,g<<bla(a,b)<<'\n';
    return 0;
}
