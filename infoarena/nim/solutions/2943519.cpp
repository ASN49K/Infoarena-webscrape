#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t;
    fin >> t;
    while (t--) {
        int n, x, ans = 0;
        fin >> n;
        for (int i = 1; i <= n; i++) {
            fin >> x;
            ans ^= x;
        }
        if (ans == 0)
            fout << "NU\n";
        else
            fout << "DA\n";
    }
    return 0;
}
