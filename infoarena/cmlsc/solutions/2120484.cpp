#include <fstream>
#include <vector>

using namespace std;

template <typename T>
using Matrix = vector<vector<T>>;

vector<int> ReadVector(ifstream &in, int size)
{
    vector<int> vec(size);
    for (auto &elem : vec) {
        in >> elem;
    }
    return vec;
}

Matrix<int> FindLengths(const vector<int> &a, const vector<int> &b)
{
    Matrix<int> len(a.size(), vector<int>(b));
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                len[i][j] = 1 + (i > 0 && j > 0 ? len[i - 1][j - 1] : 0);
                continue;
            }

            len[i][j] = 0;
            if (i > 0) {
                len[i][j] = max(len[i][j], len[i - 1][j]);
            }
            if (j > 0) {
                len[i][j] = max(len[i][j], len[i][j - 1]);
            }
        }
    }
    return len;
}

vector<int> Reconstruct(const Matrix<int> &len,
                        const vector<int> &a,
                        const vector<int> &b)
{
    vector<int> lcs(len.back().back());
    int lcs_ind = lcs.size() - 1;

    int r = len.size() - 1;
    int c = len[0].size() - 1;

    while (r >= 0 && c >= 0) {
        if (a[r] == b[c]) {
            lcs[lcs_ind] = a[r];
            lcs_ind -= 1;
            r -= 1;
            c -= 1;
            continue;
        }

        if (c == 0) {
            r -= 1;
        } else if (r == 0) {
            c -= 1;
        } else if (len[r - 1][c] > len[r][c - 1]) {
            r -= 1;
        } else {
            c -= 1;
        }
    }
    return lcs;
}

inline vector<int> FindLcs(const vector<int> &a, const vector<int> &b)
{
    auto len = FindLengths(a, b);
    auto lcs = Reconstruct(len, a, b);
    return lcs;
}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int n, m;
    fin >> n >> m;

    auto vec_a = ReadVector(fin, n);
    auto vec_b = ReadVector(fin, m);

    auto lcs = FindLcs(vec_a, vec_b);
    fout << lcs.size() << "\n";

    for (const auto &elem : lcs) {
        fout << elem << " ";
    }
    fout << "\n";

    return 0;
}