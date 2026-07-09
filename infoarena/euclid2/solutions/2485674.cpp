#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b) {
    if(b == 0)
        return a;
    return cmmdc(b, a%b);
}

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n, x, y;
    fin >> n;
    for(int i = 0; i < n; i++) {
        fin >> x >> y;
        fout << cmmdc(x, y) << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}