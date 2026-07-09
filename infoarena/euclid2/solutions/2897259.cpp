#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Check(int x, int y) {

    while (x != y) {
        if (x > y)
            x -= y;
        else
            y -= x;
    }
    return x;

}

int main() {

    int T;
    fin >> T;
    for (int i = 0; i < T; ++i) {
        int a, b;
        fin >> a >> b;
        fout << Check(a, b) << "\n";
    }
    return 0;

}
