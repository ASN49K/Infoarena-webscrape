#include <iostream>
#include <fstream>

using namespace std;

fstream f("euclid2.in");
fstream g("euclid2.out");

int cmmdc(int a, int b) {
    if (b==0) {
        return a;
    } else {
        return cmmdc(b, a % b);
    }
}

int main()
{
    int t, a, b;

    f >> t;

    while(t--) {
        f >> a >> b;
        g << cmmdc(a, b) << '\n';
    }

    return 0;
}
