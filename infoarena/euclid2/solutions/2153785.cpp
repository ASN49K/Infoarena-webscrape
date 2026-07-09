
#include <iostream>
#include <fstream>

using namespace std;

const char *IN = "euclid2.in";
const char *OUT = "euclid2.out";

void swap(int &a, int &b) {
    a ^= b; b ^= a; a ^= b;
}

int cmmdc(int a, int b){
    if (a < b) swap(a, b);
    int r = a % b;
    while (r != 0) {
        r = a % b;
        if (r == 0) break;
        a = b;
        b = r;
    };
    return b;
}

int main() {
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    int a, b;

    cin >> T;
    while (T-- >= 0) {
        cin >> a >> b;
        cout << cmmdc(a, b) << '\n';
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
