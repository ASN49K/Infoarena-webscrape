#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t, a, b, r, c, i;

int main() {
    fin >> t;

    for(i = 1;i <= t;i++) {
        fin >> a >> b;

        r = a % b;
        c = a / b;
        while(r != 0) {
            a = b;
            b = r;
            c = a / b;
            r = a % b;
        }

        fout << b << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}
