#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main() {
    int T;
    fin >> T;

    int N;
    for (int i = 1; i <= T; ++i) {
        fin >> N;
        int xor_sum = 0;
        int x;
        for (int j = 1; j <= N; ++j) {
            fin >> x;
            xor_sum ^= x;
        }
        if (xor_sum == 0) fout << "NU\n";
        else fout << "DA\n";
    }
    return 0;
}
