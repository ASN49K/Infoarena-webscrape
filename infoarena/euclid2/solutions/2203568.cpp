// https://goo.gl/fBmFxu
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define NMAX        100009
#define MMAX        200009
#define kInf        (1 << 30)
#define kInfLL      (1LL << 60)
#define kMod        666013
#define edge pair<int, int>
#define x first
#define y second

#define USE_FILES "MLC"

#ifdef USE_FILES
#define cin fin
#define cout fout
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
#endif

// number of tests from "in"
int test_cnt = 1;
void clean_test();

// your global variables are here

int gcd(int a, int b) {
    if (!b) {
        return a;
    }

    return gcd(b, a % b);
}

// your solution is here
void solve() {
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << "\n";

    if (test_cnt > 0) {
        clean_test();
    }
}


void clean_test() {
    // clean if needed
}

int main() {
    cin >> test_cnt;
    while (test_cnt--) {
        solve();
    }

    return 0;
}
