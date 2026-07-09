#include <iostream>
#include <fstream>
using namespace std;

int euclid2(int a, int b)
{
    if (a == 0)
        return b;
    else if (a > b)
        return euclid2(a % b, b);
    else
        return euclid2(b, b % a);
}

int t, a, b;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> t;
    for (int i = 0; i < t; i++)
    {
        f >> a >> b;
        g << euclid2(a, b) << "\n";
    }
    return 0;
}