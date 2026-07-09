#include <fstream>

using namespace std;

int cmmdc(int a, int b) {
    while (b!=0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t;
    fin >> t;
    while (t--) {
        int x, y;
        fin >> x >> y;
        fout << cmmdc(x, y) << '\n';
    }
    return 0;
}
