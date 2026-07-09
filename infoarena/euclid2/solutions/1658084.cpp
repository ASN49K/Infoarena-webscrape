#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t, x, y, i;

int gcd(int x, int y) {
    int aux;
    if (y > x) {
        aux = x; x = y; y = aux;
    }

    do {
        aux = x % y;
        x = y;
        y = aux;
    } while (aux != 0);

    return x;
}

int main()
{
    fin >> t;
    for (i = 1 ; i <= t ; i++) {
        fin >> x >> y;
        fout << gcd(x, y) << '\n';
    }

    return 0;
}
