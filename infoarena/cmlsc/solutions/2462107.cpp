#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

vector<int> ReadVector(ifstream &in, int size)
{
    vector<int> vec(size);
    for (auto &num : vec) {
        in >> num;
    }
    return vec;
}

vector<int> Reconstruct(const vector<vector<int>> &longest,
                        const vector<int> &a,
                        const vector<int> &b)
{
    int row = longest.size() - 1;
    int col = longest[0].size() - 1;

    vector<int> res;
    size_t lcs = longest.back().back();

    while (res.size() < lcs) {
        if (a[row] == b[col]) {
            res.push_back(a[row]);
            row -= 1;
            col -= 1;
            continue;
        }

        auto longest_up = (row <= 0 ? -1 : longest[row - 1][col]);
        auto longest_left = (col <= 0 ? -1 : longest[row][col - 1]);

        if (longest_up > longest_left) {
            row -= 1;
        } else {
            col -= 1;
        }
    }

    reverse(res.begin(), res.end());
    return res;
}

vector<int> LongestCommon(const vector<int> &a, const vector<int> &b)
{
    vector<vector<int>> longest(a.size(), vector<int>(b.size(), 0));
    for (size_t i = 0; i < a.size(); i += 1) {
        for (size_t j = 0; j < b.size(); j += 1) {
            if (a[i] == b[j]) {
                auto prev = (i > 0 && j > 0 ? longest[i - 1][j - 1] : 0);
                longest[i][j] = prev + 1;
                continue;
            }

            longest[i][j] = 0;
            if (i > 0) {
                longest[i][j] = max(longest[i][j], longest[i - 1][j]);
            }
            if (j > 0) {
                longest[i][j] = max(longest[i][j], longest[i][j - 1]);
            }
        }
    }

    return Reconstruct(longest, a, b);
}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int len_a, len_b;
    fin >> len_a >> len_b;

    auto a = ReadVector(fin, len_a);
    auto b = ReadVector(fin, len_b);

    auto res = LongestCommon(a, b);
    fout << res.size() << "\n";

    for (const auto &num : res) {
        fout << num << " ";
    }
    fout << "\n";

    return 0;
}
