#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    unsigned int a, b, t, aux;
    fin>>t;
    for (unsigned int i=1; i <= t; i++) {
        fin >> a >> b;
        while (b) {
            aux = a;
            a = b;
            b = aux % b;
        }
        fout << a << '\n';
    }
    return 0;
}
