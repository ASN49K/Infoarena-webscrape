#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n, x;

int main() {
    fin >> t;
    while(t > 0) {
        fin >> n;
        int xorSum = 0;
        for(int i = 1; i <= n; i++) {
            fin >> x;
            xorSum ^= x;
        }
        fout << (xorSum ? "DA\n" : "NU\n");
        t--;
    }
    fin.close();
    fout.close();
    return 0;
}