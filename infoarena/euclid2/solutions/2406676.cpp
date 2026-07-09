#include <fstream>
using namespace std;
int d, i, r, t;
int cmmdc(int d, int i) // cmmdc recursiv
{
    if(i == 0) return d;
    return cmmdc(i, d % i);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> t;
    while(t --)
    {
        f >> d >> i;
        while(i != 0) // cmmdc iterativ
        {
            r = d % i;
            d = i;
            i = r;
        }
        g << d << "\n";
    }
    return 0;
}
