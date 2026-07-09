#include <fstream>
using namespace std;
int euclid(int d, int i) // cmmdc recursiv
{
    if(i == 0) return d;
    return euclid(i, d % i);
}
int d, i, r, t;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> t;
    while(t --)
    {
        f >> d >> i;
        while(i)
        {
            r = d % i;
            d = i;
            i = r;
        }
        g << d << "\n";
    }
    return 0;
}
