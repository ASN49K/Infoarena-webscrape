#include <fstream>
using namespace std;

#define NUME "euclid2"
ifstream fi(NUME".in");
ofstream fo(NUME".out");

int cmmdc(int a, int b) {
    if (b == 0) return a;
    return cmmdc(b, a%b);
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
