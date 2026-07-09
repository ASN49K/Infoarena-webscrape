#include <array>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

constexpr int NMAX = 1031;
using intVector=array<int, NMAX>;
using matrix=array<intVector, NMAX>;

int main() {
    intVector v, w, r;
    matrix lcsDp;
    int N, M;
    ifstream in{"cmlsc.in"};
    ofstream out{"cmlsc.out"};

    in >> N >> M;

    for (int i = 0; i < N; ++i) in >> v[i];
    for (int i = 0; i < M; ++i) in >> w[i];
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (v[i - 1] == w[j - 1]) {
                lcsDp[i][j] = 1 + lcsDp[i - 1][j - 1];
            }
            else {
                lcsDp[i][j] = max(lcsDp[i - 1][j], lcsDp[i][j - 1]);
            }
        }
    }

    for (int i = N, j = M, k = lcsDp[N][M] - 1; i && j;) {
        if (v[i - 1] == w[j - 1]) {
            r[k--] = v[i-1];
            --i;
            --j;
        }
        else if (lcsDp[i - 1][j] > lcsDp[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }

    out << lcsDp[N][M] << '\n';
    copy (r.begin(), r.begin() + lcsDp[N][M], ostream_iterator<int>{out, " "});

    return 0;
}
