#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int T;
    fin >> T;
    int n, val, xorSum;
    while (T--) {
        xorSum = 0;
        fin >> n;
        for (int i = 1; i <= n; ++i) {
            fin >> val;
            xorSum ^= val;
        }
        fout << (xorSum == 0 ? "DA\n" : "NU\n");
    }
    return 0;
}
