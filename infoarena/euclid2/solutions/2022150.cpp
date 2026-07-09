#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long long T, a, b;

int main()
{
    f >> T;
    while(T--)
    {
        f >> a >> b;
        int c;
        while(b)
        {
            c = a % b;
            a = b;
            b = c;
        }
        g << a << '\n';
    }
    return 0;
}
