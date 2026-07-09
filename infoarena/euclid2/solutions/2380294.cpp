#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main() {
    int n, a, b, r;
    fin >> n;
    for(; n; n--) {
        fin >> a >> b;
        while(b) {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << "\n";
    }
}

