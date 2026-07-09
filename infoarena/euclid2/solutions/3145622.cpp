#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b) {
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int T, a, b;
    fin >> T;
    for(int i = 1; i <= T; i ++) {
        fin >> a >> b;
        fout << euclid(a, b) << "\n";
    }
}
