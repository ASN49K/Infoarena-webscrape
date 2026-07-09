#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;
int i, n, a, b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
    int c = 0;
    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    f >> n;
    for(i = 1; i <= n; i++)
    {
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }
    return 0;
}
