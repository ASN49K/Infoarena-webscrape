#include <fstream>

using namespace std;

ifstream fin ("nim.in");
ofstream fout("nim.out");

int t, n, x, s;

int main() {
    fin >> t;
    while (t--) {
        fin >> n;
        s = 0;
        for (int i = 1; i <= n; i++) {
            fin >> x;
            s ^= x;
        }
        if (s)
            fout << "DA\n";
        else
            fout << "NU\n";
    }

    return 0;
}
