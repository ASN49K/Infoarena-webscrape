#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t;

int euclid(int a, int b) {
    if (a == b) {
        return a;
    }
    if (a < b) {
        swap(a, b);
    }
    return euclid(a - b, b);
}

int main() {
    int a, b;
    fin>>t;
    for (int i=0; i<t; i++) {
        fin>>a>>b;
        fout<<euclid(a, b)<<"\n";
    }
    return 0;
}