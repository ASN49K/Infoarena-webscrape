#include <fstream>

std::ifstream fin("nim.in");
std::ofstream fout("nim.out");

int t, n;

int main() {
    int x;

    fin >> t;
    while (t--) {
        fin >> n;

        int xorSum = 0;
        for (int i = 0; i < n; i++) {
            fin >> x;
            xorSum ^= x;
        }
        fout << (xorSum ? "DA\n" : "NU\n");
    }

    fout.close();
    return 0;
}
