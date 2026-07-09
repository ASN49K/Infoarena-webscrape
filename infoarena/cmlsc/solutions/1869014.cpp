#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

vector<int> FindLcs(const vector<int> &a, const vector<int> &b)
{
    vector<vector<int>> d(a.size(), vector<int>(b.size(), 0));
    for (unsigned i = 0; i < a.size(); ++i) {
        for (unsigned j = 0; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                d[i][j] = (i > 0 && j > 0) ? d[i - 1][j - 1] + 1 : 1;
            } else {
                if (i > 0) {
                    d[i][j] = max(d[i][j], d[i - 1][j]);
                }
                if (j > 0) {
                    d[i][j] = max(d[i][j], d[i][j - 1]);
                }
            }
        }
    }

    vector<int> lcs;
    int row = a.size() - 1, col = b.size() - 1;

    while (row >= 0 && col >= 0) {
        if (a[row] == b[col]) {
            lcs.push_back(a[row]);
            row--;
            col--;
        } else if (col == 0 || d[row - 1][col] > d[row][col - 1]) {
            --row;
        } else {
            --col;
        }
    }
    reverse(lcs.begin(), lcs.end());

    return lcs;
}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int n, m;
    fin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        fin >> b[i];
    }

    auto lcs = FindLcs(a, b);
    fout << lcs.size() << "\n";
    for (int i : lcs) {
        fout << i << " ";
    }

    return 0;
}
