#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int n, int m)
{
    while (m != 0)
    {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}
int main()
{
    int T, a, b;
    f >> T;
    for(int i=1; i<=T; i++)
    {
        f >> a >> b;
        g << cmmdc(a,b) << '\n';
    }
    g.close();
    return 0;
}
