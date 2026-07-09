#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc(int a, int b) {
    if (!b)
        return a;
    return cmmdc(b, a % b);
}

int main() {
    fin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    fin >> t;

    while (t--) {
        int a, b;
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }

    return 0;
}
