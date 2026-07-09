#include <fstream>

using namespace std;

int n, a, b, r;

int cmmdc()
{
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f >> a;

    while(f >> a >> b)
        g << cmmdc() << "\n";

    return 0;
}
