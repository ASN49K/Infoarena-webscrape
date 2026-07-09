#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main() {
    int t, n, x, sum;
    fin >> t;
    for (int i = 0; i < t; ++i) {
        sum = 0;
        fin >> n;
        for (int j = 0; j < n; ++j) {
            fin >> x;
            sum ^= x;
        }
        if (sum)
            fout << "DA\n";
        else
            fout << "NU\n";
    }
    return 0;
}
