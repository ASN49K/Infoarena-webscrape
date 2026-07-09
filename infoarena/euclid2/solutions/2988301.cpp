#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int fun(int a, int b)
{
    int d = a;
    while(a % d != 0 || b % d != 0)
    {
        d--;
    }
    return d;
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
