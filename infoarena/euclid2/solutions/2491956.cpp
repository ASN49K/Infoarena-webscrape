#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g ("euclid2.out");
int cmmdc (long long a, long long b) {
    long long r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int T;
    f >> T;
    long long x, y;
    while (T--) {
        f >> x >> y;
        g <<  cmmdc(x, y) << "\n";
    }
    f.close();
    g.close();
    return 0;
}
