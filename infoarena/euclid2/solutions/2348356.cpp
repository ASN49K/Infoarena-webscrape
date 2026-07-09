#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int Euclid(int a, int b) {
    if(b == 0) {
        return a;
    }
    return Euclid(b, a % b);
}
int main() {
    int T, a, b;
    in >> T;

    for(int i = 0; i < T; i++) {
        in >> a >> b;
        out << Euclid(a, b) << '\n';
    }
    return 0;
}