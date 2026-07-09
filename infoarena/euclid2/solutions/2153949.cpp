
#include <iostream>
#include <fstream>

using namespace std;

const char *IN = "euclid2.in";
const char *OUT = "euclid2.out";

ifstream fin(IN);
ofstream fout(OUT);

void swap(int &a, int &b) {
    a ^= b; b ^= a; a ^= b;
}

int cmmdc(int a, int b){
    if (a < b) swap(a, b);
    int r = a % b;
    while (r != 0) {
        r = a % b;
        if (r == 0) break;
        a = b;
        b = r;
    };
    return b;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    int a, b;

    fin >> T;
    while (T-- > 0) {
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}
