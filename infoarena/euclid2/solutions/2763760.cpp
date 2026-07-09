#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b;

int cmmdc(int x, int y) {
    while(y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main() {
    fin >> n;
    while(n > 0) {
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
        n--;
    }
    fin.close();
    fout.close();
    return 0;
}
