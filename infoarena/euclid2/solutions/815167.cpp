#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b;

int main() {
    fin >> n;
    for (; n > 0; n--) {
        fin >> a >> b;
        while (a % b) {
            if (a > b)
                a %= b;
            else
                b %= a;
        }
        if (a > b)
            fout << b << '\n';
        else
            fout << a << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
