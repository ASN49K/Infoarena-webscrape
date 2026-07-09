#include <iostream>
#include <fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

void solve() {

    int n;
    in >> n;
    int x;
    int xo = 0;

    for(int i = 1; i <= n; i++) {
        in >> x;
        xo ^= x;
    }

    if(xo != 0)
        out << "DA" << '\n';
    else
        out << "NU" << '\n';

}

int main() {

    int t;
    in >> t;

    for(int i = 1; i <= t; i++)
        solve();

    return 0;
}
