#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int n, i, x, s, t;

int main() {
    for (f >> t; t--;){

    f >> n;
    s = 0;
    for (i = 1; i <= n; i++) {
        f >> x;
        s ^= x;
    }
    g << (s==0?"NU\n":"DA\n");

    }
}
