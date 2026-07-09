#include <fstream>
using namespace std;

void euclid(int a, int b, int *d)
{
    if (b == 0)
        *d = a;
    else
        euclid(b, a % b, d);
}

int main()
{
    int a,b,T,d;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    for (f >> T ; T ; T--)
    {
        f >> a >> b;

        euclid(a , b , &d );

        g << d << "\n";
    }
    f.close();
    g.close();
    return 0;
}
