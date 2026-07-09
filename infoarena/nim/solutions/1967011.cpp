#include <fstream>

using namespace std;

int main() {
    ifstream fin("nim.in");
    ofstream fout("nim.out");
    int t;
    fin >> t;
    while (t--) {
        int n;
        fin >> n;
        int v = 0;
        int a;
        while (n--) {
            fin >> a;
            v ^= a;
        }
        fout << (v != 0 ? "DA\n" : "NU\n");
    }
    return 0;
}
