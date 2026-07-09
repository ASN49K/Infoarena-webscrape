#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b) {
    if(a < b)
        swap(a, b);
    while(b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int n;
    fin >> n;
    while(n) {
        int x, y;
        fin >> x >> y;
        fout << euclid(x, y) << "\n";
        n--;
    }

    fin.close();
    fout.close();
    return 0;
}
