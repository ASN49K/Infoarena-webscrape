#include <iostream>
#include <fstream>

using namespace std;

ifstream fcin("euclid2.in");
ofstream fcout("euclid2.out");

int lnko(int a, int b)
{
    if (a == b || b == 0)
        return a;
    while (b)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    int t, x, y;
    fcin >> t;
    while (t)
    {
        fcin >> x >> y;
        fcout << lnko(x, y) << '\n';
        --t;
    }
}
