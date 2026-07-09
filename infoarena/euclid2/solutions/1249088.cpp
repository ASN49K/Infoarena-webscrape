#include <fstream>

using namespace std;

int cmmdc(int a, int b) {

    int r;

    while(b) {
        r = a % b;
        a = b;
        b = r;
        }

    return a;

}
int main() {

    int a, b, T;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    in >> T;

    while(T--) {

        in >> a >> b;
        out << cmmdc(a, b) << '\n';

        }

    return 0;

}
