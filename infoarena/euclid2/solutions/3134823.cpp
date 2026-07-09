#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    int t, a, b, c;
    fin >> t;
    while (t != 0) {
        --t;
        fin >> a >> b;
        while (b != 0) {
            c = a % b;
            a = b;
            b = c;
        }
        fout << a << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
