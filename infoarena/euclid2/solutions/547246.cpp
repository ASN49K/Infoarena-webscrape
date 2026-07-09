#include <fstream>
using namespace std;

int main()
{
    int t,r,i;
    long a,b;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>t;

    for (i=1; i<=t; i++)
    {
    f>>a;
    f>>b;
    r=a%b;
    while (r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<"\n";
    }
    g.close();
    f.close();

    return 0;
}
