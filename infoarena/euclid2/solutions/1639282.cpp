#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

long cmmdc (long a, long b)
    {
        if (!b)
            {
                return a;
            }
        return (b, a%b);
    }

int main()
{
    long t, i, a, b, r;
    f>>t;
    for (i=1; i<=t; i++)
        {
            f>>a>>b;
            g<<cmmdc (b,a)<<endl;
        }
    f.close ();
    g.close();
    return 0;
}
