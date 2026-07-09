#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int fun(int a, int b)
{
    while (b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int n;
    f >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        f >> x >> y;
        g << fun(x, y) << "\n";
    }
}
