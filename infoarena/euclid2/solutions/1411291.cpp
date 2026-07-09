// cmmdc sau __gcd
// log(max(a,b))
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,a,b;

int cmmdc(int a, int b)
{
    while (a!=b)
    {
        if (a>b) a=a-b;
        else b=b-a;
    }
    return a;
}

//(a,b)=(b, a %b) = ... = (d, 0) = d
int cmmdc2(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    f>>n;
    for (int i=1; i<=n; ++i)
    {
        f>>a>>b;
        g<<cmmdc2(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
