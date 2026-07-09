#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a, int b)
{
    if (!b) return a;
    return euclid(b, a%b);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n, a, b;
    f>>n;
    for (; n; n--)
    {
        f>>a>>b;
        g<<euclid(a, b)<<"\n";
    }
    return 0;
}
