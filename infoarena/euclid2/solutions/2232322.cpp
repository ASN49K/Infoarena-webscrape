#include <fstream>
#include <iostream>

using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T, a, b;
    f >> T;
    while (T--)
    {
        f >> a >> b;
        g << GCD(a, b) << '\n';
    }
    f.close();
    g.close();
    return 0;
}
