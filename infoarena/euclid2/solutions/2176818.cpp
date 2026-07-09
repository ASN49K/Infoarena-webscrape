#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int i, d, r, t, j;
    f >> t;
    for(j = 1; j <= t; j ++)
    {
    f >> d >> i;
    r = d%i;
    while(r)
    {
        d = i;
        i = r;
        r = d%i;
    }
    g << i;
    g << endl;
    r = 0;
    }
    return 0;
}
