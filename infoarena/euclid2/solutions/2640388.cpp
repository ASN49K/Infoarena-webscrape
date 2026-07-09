#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b) {
    if (a == b)
        return a;
    if (a > b)
        cmmdc(a - b, b);
    else
        cmmdc(a, b - a);
}
int main() {
    int n;
    fin >> n;
    while (n) {
        int a, b;
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
        --n;
    }
}
