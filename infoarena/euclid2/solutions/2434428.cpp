#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b) {
    if (!b)
        return a;
    return euclid(b, a % b);
}

/*int prime(int a, int b) {
    if (euclid(a, b) == 1)
        return 0;
    else
        return euclid(a, b);
}*/

int main() {
    int T, a, b;
    fin >> T;

    for (int i = 0; i < T; i++) {
        fin >> a >> b;
        fout << euclid(a, b) << endl;
    }
}
