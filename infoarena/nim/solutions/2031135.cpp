#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int k, n, v[100];

int main () {
   fin >> k;
    for (int j = 1; j <= k; j++) {
        fin >> n;
        for (int i = 1; i <= n; i++) {
            fin >> v[i];
        }
        if (n % 2 == 0) {
            fout << "NU" << '\n';
        }
        else
            fout << "DA" << '\n';
    }
}
