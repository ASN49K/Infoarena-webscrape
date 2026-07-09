#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int n,int m)
{
    int x;
    while (m)
    {
        x = n % m;
        n = m;
        m = x;
    }
    return n;
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
