#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n;

int main() {
    int a, b, r;
    in >> n;
    while(n--) {
        in >> a >> b;
        r = 1;
        while (r) {
            r = a % b;
            a = b;
            b = r;
        }
        out << a << '\n';
    }
    in.close();
    out.close();
    return 0;
}
