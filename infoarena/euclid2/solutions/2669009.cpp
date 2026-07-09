#include <bits/stdc++.h>
using namespace std;
#define STOP fout.close(); exit(EXIT_SUCCESS);
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
///***********************

int getGcd(int a, int b) {
    int r;
    while (a % b) {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int main() {
    int t, a, b;
    for (fin >> t; t; t--) {
        fin >> a >> b;
        fout << getGcd(a, b) << '\n';
    }
    STOP
}
