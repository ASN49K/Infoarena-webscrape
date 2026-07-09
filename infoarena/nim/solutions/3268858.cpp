#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main() {
    int t;
    fin >> t;

    while (t--) {
        int n;
        fin >> n;

        int s = 0;
        while (n--) {
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
