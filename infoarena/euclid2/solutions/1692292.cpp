#include <fstream>
#include <math.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main() {
    long long t,a,b,i;
    f >> t;
    f.close();
    for ( i = 1; i <= t; i ++ ) {
        f>>a>>b;
        if (b > a)
            swap(a,b);
        a=a%b;
        if (a == 0)
            g<<b<<'\n';
        else
            g<<a<<'\n';
    }
    g.close();
    return 0;
    }
