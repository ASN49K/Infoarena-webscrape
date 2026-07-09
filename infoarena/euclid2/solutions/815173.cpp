#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b, aux;

int main() {
    fin >> n;
    for (; n > 0; n--) {
        fin >> a >> b;
        while (a % b) {
            a %= b;
            aux = a;
            a = b;
            b = aux;
        }
        fout << b << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
