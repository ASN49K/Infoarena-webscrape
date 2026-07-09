#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long t,a,b;

long cmmdc(long a, long b)
{
    long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    f>>t;
    while(t--)
    {
     f>>a>>b;
     g<<cmmdc(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
