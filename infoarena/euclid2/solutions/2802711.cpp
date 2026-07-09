#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        fin >> a >> b;
        while (b) {
            int r = a % b;
            a = b;
            b = r;
        }
        fout << a << "\n";
    }
}
