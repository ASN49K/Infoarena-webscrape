#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#define NMax 100001
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T;
long long a, b;

int main()
{
    f >> T;
    ++T;
    while(--T)
    {
        f >> a >> b;
        long long c;
        while(b)
        {
            c = a % b;
            a = b;
            b = c;
        }
        g << a << '\n';
    }
    return 0;
}
