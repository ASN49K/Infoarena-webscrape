#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid (int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int n, a[100001], b[100001];
    fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n ; ++i) {
        fout << euclid(a[i], b[i]) << "\n";
    }
    return 0;
}
