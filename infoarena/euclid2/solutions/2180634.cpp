#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a, b, r;

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
    f >> a;

    while(f >> a >> b)
        g << cmmdc() << endl;

    return 0;
}
