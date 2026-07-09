#include <fstream>
using namespace std;
int r, d, i, n;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> n;
    while(n --)
    {
        f >> d >> i;
        r = d % i;
        while(r)
        {
            d = i;
            i = r;
            r = d % i;
        }
        g << i << "\n";
    }
    f.close();
    g.close();
    return 0;
}
