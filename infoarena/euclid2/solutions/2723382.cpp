#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
    if (a%b == 0) return b;
    return cmmdc (b,a%b);
}

void test()
{
    int a,b;
    f >> a >> b;
    g << cmmdc(a,b) << '\n';
}

int main()
{
    int t;
    f >> t;
    while(t)
    {
        test();
        t--;
    }
    return 0;
}
