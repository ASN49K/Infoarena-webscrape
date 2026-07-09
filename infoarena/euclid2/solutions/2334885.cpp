#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

inline int Euclid(int a, int b) {
    int r;
    do {
        r = a % b;
        a = b;
        b = r;
    } while (r);

    return a;
}

inline void Read() {
    int N, x, y;

    fin >> N;

    while (N--) {
        fin >> x >> y;

        fout << Euclid(x, y) << "\n";
    }
}

int main () {
    Read();

    fin.close(); fout.close(); return 0;
}
