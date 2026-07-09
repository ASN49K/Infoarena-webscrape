#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int t, a, b;
    fin >> t;
    while (t) {
        fin >> a >> b;
        fout << euclid(a, b) << '\n';
        --t;
    }
    return 0;
}
