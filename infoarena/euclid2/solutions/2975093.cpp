#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b) {
    while(b != 0) {
        int d = a % b;
        a = b;
        b = d;
    }
    return a;
}

int main() {

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int a, b, n, i;
    fin >> n;
    for(i = 0; i < n; i ++) {
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
