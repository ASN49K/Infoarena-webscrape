#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int x,a,b,r,i;
    f>>x;
    for (i=0;i<=x;i++)
    {
        f>>a>>b;
        r=a%b;
        while (b)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<a;
        g<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
