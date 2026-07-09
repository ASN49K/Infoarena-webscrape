#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int cmmdc (int a, int b)
    {
        if (!b)
            {
                return a;
            }
        return (b, b%a);
    }

int main()
{
    int t, i, a, b, r;
    f>>t;
    for (i=1; i<=t; i++)
        {
            f>>a>>b;
            g<<cmmdc (a,b)<<endl;
        }
    f.close ();
    g.close();
    return 0;
}
