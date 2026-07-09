#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, a, b;

int GCD(int a, int b) {
    if (!b)
        return a;
    return GCD(b, a % b);
}

int main() {
    fin >> T;
    for (; T; --T) {
        fin >> a >> b;
        fout << GCD(a, b) << '\n';
    }
}