#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");

int cmmdc(int a, int b)
{
    if(!b) return a;
    return cmmdc(b, a % b);
}

int main()
{
    int i, t, a, b;
    f >> t;
    for(i=0; i<t;i++)
    {
        f >> a >> b;
        o << cmmdc(a, b) << '\n';
    }
    return 0;
}
