#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long euclid(long a,long b)
{
    long c;
    while(b)
    {
        c=a%b; a=b; b=c;
    }
    return a;
}

int main()
{
    unsigned T; long a,b;
    f>>T;
    while(T--)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
