#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid.in");
ofstream g("euclid.out");

int cmmdc(int a, int b)
{
    if (!b)
    {
        return a;
    }
    return cmmdc(b, a%b);
}

int main()
{
    int n, x, y;
    f >> n;
    for (int i=0; i<n; i++)
    {
        f >> x >> y;
        g << cmmdc(x,y) << endl;
    }
    return 0;
}
