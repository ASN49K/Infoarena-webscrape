#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main() {
    int t;
    fin >> t;

    for (int i = 1; i <= t; ++i) {
        int n;
        fin >> n;

        int s = 0;
        for (int j = 1; j <= n; ++j) {
            int x;
            fin >> x;
            s ^= x;
        }

        if (s != 0) {
            fout << "DA\n";
        } else {
            fout << "NU\n";
        }
    }
    return 0;
}
