#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(unsigned int x, unsigned int y)
{
    while(x != y)
        if(x > y)
            x -= y;
        else y -= x;
    return x;
}
int main()
{
    unsigned int t, a, b;
    f >> t;
    while(t)
    {
        f >> a >> b;
        g << euclid(a,b) << endl;
        t--;
    }
    return 0;
}
