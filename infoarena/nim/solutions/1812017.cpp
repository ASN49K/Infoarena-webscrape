# include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int T, i, n, x, s;

int main() {
    for (fin >> T; T; --T) {
        fin >> n;
        fin >> s;
        for (i=2; i<=n; i++) {
            fin >> x;
            s ^= x;
        }
        if (s > 0)
            fout << "DA\n";
        else
            fout << "NU\n";
    }
    return 0;
}
