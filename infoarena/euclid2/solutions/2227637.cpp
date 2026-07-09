#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a, int b)
{
    while (b)
    {
        int aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}
int main()
{
    int a, b, T;
    g >> T;
    while (T--)
    {
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }
    return 0;
}
