#include <iostream>
#include <fstream>
#include <vector>

std::ifstream f("euclid2.in");
std::ofstream g("euclid2.out");

int a, b, T, d;

int cmmdc(int x, int y)
{
    if (y == 0)
        return x;
    else
        return cmmdc(y, x % y);
}

int main()
{
    f >> T;
    while (T--)
    {
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }
    
    f.close();
    g.close();

    return 0;
}