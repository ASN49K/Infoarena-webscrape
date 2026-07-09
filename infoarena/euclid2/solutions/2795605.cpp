#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int n,int m)
{
    if (!m) return n;
    return cmmdc(m, n % m);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream o("euclid2.out");
    int n;
    f >> n;
    int a, b;
    while (n)
    {
        f >> a >> b;
        o << cmmdc(a,b) << endl;
    }
    return 0;
}
