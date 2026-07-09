#include <fstream>
using namespace std;

int t, n, rez;

int main() {
    int i, j, k;
    ifstream fin("nim.in");
    ofstream fout("nim.out");
    fin >> t;
    for(i = 1; i <= t; ++i) {
        fin >> n; rez = 0;
        for(j = 1; j <= n; ++j) {
            fin >> k;
            rez ^= k;
        }
        if(rez == 0)
            fout << "NU\n";
        else
            fout << "DA\n";
    }
    fout.close();
    return 0;
}
