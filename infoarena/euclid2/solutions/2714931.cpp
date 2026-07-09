#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");
int euclid(int a, int b)
{
    if (!b)
        return a;
    return euclid(b, a % b);
}
int main()
{
    int n, a, b;
    f >> n;
    while (n--)
    {
        f >> a >> b;
        o << euclid(a, b) << "\n";
    }
}