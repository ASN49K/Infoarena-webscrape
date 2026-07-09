// https://goo.gl/fBmFxu
#include <bits/stdc++.h>
using namespace std;

#define NMAX        100009
#define MMAX        200009
#define kInf        (1 << 30)
#define kInfLL      (1LL << 60)
#define kMod        666013
#define edge pair<int, int>
#define x first
#define y second

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
    // din cauza ca fac redirectari, salvez starea lui cin si cout
    auto cin_buff = cin.rdbuf();
    auto cout_buff = cout.rdbuf();

    // las liniile urmatoare daca citesc din fisier
    ifstream fin("euclid2.in");
    cin.rdbuf(fin.rdbuf()); // save and redirect

    // las liniile urmatoare daca afisez in fisier
    ofstream fout("euclid2.out");
    cout.rdbuf(fout.rdbuf()); // save and redirect


    cin >> test_cnt;
    while (test_cnt--) {
        solve();
    }

    // restore pentru cin si cout
    cin.rdbuf(cin_buff);
    cout.rdbuf(cout_buff);

    return 0;
}
