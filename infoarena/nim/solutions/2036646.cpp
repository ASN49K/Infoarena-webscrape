#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n;

void NIM () {
    fin >> n;
    int x, s = 0;
    for (int i = 1; i <= n; i++) {
        fin >> x;
        s = s ^ x;
    }
    if (s > 0) {
        fout << "DA" << endl;
    }
    else
        fout << "NU" << endl;
}

int main () {
    fin >> t;
    while (t) {
        NIM();
        t--;
    }
}
