#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

short unsigned T, a, b;

short unsigned sal_Euclid(short unsigned a, short unsigned b) {
    if (b == 0)
        return a;
    return sal_Euclid (b, a % b);
}

int main() {
    f >> T;
    while (T)
        f >> a >> b, g << sal_Euclid (a, b) << '\n', T --;
    return 0;
}
