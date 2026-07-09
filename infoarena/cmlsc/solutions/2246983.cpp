#include <fstream>
#include <vector>

using namespace std;

vector<int> ReadVector(ifstream &fin, int len)
{
    vector<int> vec(len);
    for (auto &elem : vec) {
        fin >> elem;
    }
    return vec;
}

vector<int> BuildLcs(const vector<vector<int>> &lcs_len,
                     const vector<int> &vec1,
                     const vector<int> &vec2)
{
    vector<int> lcs(lcs_len.back().back());
    int index = lcs.size() - 1;

    int row = vec1.size() - 1;
    int col = vec2.size() - 1;

    while (row >= 0 && col >= 0) {
        if (vec1[row] == vec2[col]) {
            lcs[index] = vec1[row];
            index -= 1;
            row -= 1;
            col -= 1;
        } else {
            auto up_len = (row > 0 ? lcs_len[row - 1][col] : -1);
            auto left_len = (col > 0 ? lcs_len[row][col - 1] : -1);
            (up_len > left_len ? row : col) -= 1;
        }
    }
    return lcs;
}

vector<int> FindLcs(const vector<int> &vec1, const vector<int> &vec2)
{
    int len1 = vec1.size();
    int len2 = vec2.size();

    vector<vector<int>> lcs_len(len1, vector<int>(len2, 0));

    for (auto i = 0; i < len1; i += 1) {
        for (auto j = 0; j < len2; j += 1) {
            if (vec1[i] == vec2[j]) {
                auto prev = (i > 0 && j > 0 ? lcs_len[i - 1][j - 1] : 0);
                lcs_len[i][j] = prev + 1;
            } else {
                auto prev = (i > 0 ? lcs_len[i - 1][j] : 0);
                prev = max(prev, (j > 0 ? lcs_len[i][j - 1] : 0));
                lcs_len[i][j] = prev;
            }
        }
    }

    return BuildLcs(lcs_len, vec1, vec2);
}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int len1, len2;
    fin >> len1 >> len2;

    auto vec1 = ReadVector(fin, len1);
    auto vec2 = ReadVector(fin, len2);

    auto lcs = FindLcs(vec1, vec2);
    fout << lcs.size() << "\n";

    for (const auto &elem : lcs) {
        fout << elem << " ";
    }
    fout << "\n";

    return 0;
}
