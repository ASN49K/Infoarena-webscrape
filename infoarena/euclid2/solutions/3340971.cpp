#include <iostream>
#include <fstream>

using namespace std;

string name = "euclid2";
ifstream f(name + ".in");
ofstream g(name + ".out");

long long cmmdc(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    long long int a, b;
    f >> a >> b;
    g << cmmdc(a, b);
    return 0;
}