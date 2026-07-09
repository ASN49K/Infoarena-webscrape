#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    ifstream f("in.in");
    ofstream g("out.out");
    unsigned T;
    f >> T;
    for(unsigned i = 1; i <= T; i++)
    {
        unsigned x, y, r;
        f >> x >> y;
        while(y != 0)
        {
            r = x % y;
            x = y;
            y = r;
        }
        g << x << '\n';
    }
    return 0;
}
