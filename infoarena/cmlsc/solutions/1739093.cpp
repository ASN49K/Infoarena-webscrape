#include <fstream>
#include <vector>
#include <string>
#include <list>

#define problema "cmlsc"

using namespace std;

vector<int> a, b;
vector<int> result;
int n, m;

inline int max(int x, int y) { return x >= y ? x : y; }

inline void solve()
{
    vector<vector<int>> c(n + 1, vector<int>(m + 1, 0));
    for (auto i = 1; i <= n; ++i)
        for (auto j = 1; j <= m; ++j)
            if (a[i - 1] == b[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
    list<int> s;
    auto i = n, j = m;
    while (i > 0 && j > 0)
        if (a[i - 1] == b[j - 1]) {
            s.push_back(a[i - 1]);
            --i;
            --j;
        }
        else if (c[i][j] == c[i][j - 1])
            --j;
        else
            --i;
    result = vector<int>(s.rbegin(), s.rend());
}

inline void read(ifstream& fin)
{
    fin >> n >> m;
    a.reserve(n);
    b.reserve(m);

    int x;
    for (auto i = 0; i < n; ++i) {
        fin >> x;
        a.push_back(x);
    }

    for (auto i = 0; i < m; ++i) {
        fin >> x;
        b.push_back(x);
    }
}

inline void write(ofstream& fout)
{
    for (auto i = 0; i < result.size(); ++i)
        fout << result[i] << ' ';
}

int main()
{
    ifstream fin(problema ".in");
    ofstream fout(problema ".out");

    read(fin);
    solve();
    write(fout);

    fin.close();
    fout.close();
    return 0;
}