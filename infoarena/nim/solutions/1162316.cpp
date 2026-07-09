#include <fstream>
using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int t, n;

int main() {
    fin >> t;
    while (t--) {
        fin >> n;
        int x = 0;
        while (n--) {
            int nr;
            fin >> nr;
             x ^= nr;
        }
        if (x)
            fout << "DA\n";
        else
            fout << "NU\n";
    }
}
