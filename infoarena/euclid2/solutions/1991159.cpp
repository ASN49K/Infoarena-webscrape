#include <iostream>
#include <fstream>

using namespace std;

int T;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int euclid (int &x, int &y)
{
    int rest;
    while (y)
    {
        rest = x % y;
        x = y;
        y = rest;
    }
    return x;
}

void functie (int T)
{
    int x, y;
    for (int i = 0; i < T; i++)
    {
        f >> x >> y;
        g << euclid (x, y) << endl;
    }
}

int main()
{
    f >> T;
    if (T >= 1 && T <= 100000)
        functie (T);
    return 0;
}
