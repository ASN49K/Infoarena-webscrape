#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    if(!b) return a;
    return cmmdc(b, a % b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a, b, t;

    f >> t;

    for(t; t; --t)
    {
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }

    return 0;
}
