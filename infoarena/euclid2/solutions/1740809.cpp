#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    long x,a,b,r,i;
    f>>x;
    for (i=1;i<=x;i++)
    {
        f>>a>>b;
        r=a%b;
        while (r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<'/n';
    }
    f.close();
    g.close();
    return 0;
}
