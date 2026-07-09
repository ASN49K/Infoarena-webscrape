#include <fstream>
#include <algorithm>
#include <vector>
#define nmax 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[nmax], b[nmax], matrix[nmax][nmax];

vector < int > random_lcs;

void go_back() {
    int i, j;
    for (i = n, j = m; i; )
        if (a[i] == b[j])
            random_lcs.push_back(a[i]), --i, --j;
        else
            if (matrix[i - 1][j] > matrix[i][j - 1])
                --i;
            else
                --j;
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = 1; i <= m; ++i)
        fin >> b[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j])
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            else
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
    go_back();
    fout << random_lcs.size() << "\n";
    for (int i = random_lcs.size() - 1; i >= 0; --i)
        fout << random_lcs[i] << " ";
    return 0;
}
