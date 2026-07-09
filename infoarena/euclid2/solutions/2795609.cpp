#include <iostream>
#include <fstream>
using namespace std;
int n, a, b;
int cmmdc(int t,int m)
{
    if (!m) return t;
    return cmmdc(m, t % m);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream o("euclid2.out");
    f >> n;
    for(;n;n--)
    {
        f >> a >> b;
        o << cmmdc(a,b) << "\n";
    }
    return 0;
}
