#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T, a, b;

int sal_Euclid(int a, int b) {
    if (b)
        return sal_Euclid (b, a % b);
    else
        return a;
}

int main() {
    f >> T;
    while (T --)
        f >> a >> b, g << sal_Euclid (a, b) << '\n';
    return 0;
}
