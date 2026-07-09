#include <fstream>
using namespace std;

#define NUME "euclid2"
ifstream fi(NUME".in");
ofstream fo(NUME".out");

int cmmdc(int a, int b) {
    while (a | b) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a | b;
}

int main()
{
    int T, x, y;
    fi >> T;
    while (T--) {
        fi >> x >> y;
        fo << cmmdc(x, y) << "\n";
    }
    return 0;
}
