#include <iostream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {

    int t, a, b, v[100001], r = 0;

    in >> t;
    for (int i = 0; i < t; i++) {
        in >> a >> b;
        v[++r] = cmmdc(a, b);
    }
    for (int i = 1; i <= r; i++) {
        out << v[i] << endl;
    }
    return 0;
}
