#include <fstream>
using namespace std;

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int T;
    fin >> T;

    for (int i = 1; i <= T; i++) {
        int a, b;
        fin >> a >> b;

        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        fout << a << endl;
    }
    return 0;
}