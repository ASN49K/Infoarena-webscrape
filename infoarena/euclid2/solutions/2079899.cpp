#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main() {
    int T, a, b;
    in >> T;
    for (int i = 0; i < T; i++) {
        in >> a >> b;
        out << gcd(a, b) << '\n';
    }
    in.close();
    out.close();
}
