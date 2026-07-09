#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a, b, r, n;

int main() {
    fin >> n;
    for (; n; n--) {
        fin >> a >> b;
        while (b) {
            r = a % b;
            a = b;
            b = r;
            //cout << a << " " << b << " " << r << "\n";
        }
        fout << a << '\n';
    }


    return 0;
}