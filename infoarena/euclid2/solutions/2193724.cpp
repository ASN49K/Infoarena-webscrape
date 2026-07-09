#include <iostream>
#include <fstream>
using namespace std;
int n, a, b;
int cmmdc(int a, int b)
{
    if(!b)
        return a;
    return cmmdc(b, a % b);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> n;
    for(int i = 0; i < n; ++i)
    {
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }
    f.close();
    g.close();
}
