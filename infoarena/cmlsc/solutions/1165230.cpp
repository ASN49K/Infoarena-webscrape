#include <fstream>
#include <vector>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int N = 1027;

int a[N], b[N], d[N][N], m, n;
vector <int> sol;

int main() {
    fin >> m >> n;
    for (int i = 1; i <= m; ++i)
        fin >> a[i];
    for (int j = 1; j <= n; ++j)
        fin >> b[j];
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            if (a[i] == b[j])
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = max (d[i-1][j], d[i][j-1]);
        }
    int i = m, j = n;
    while (i && j) {
        if (a[i] == b[j]) {
            sol.push_back (i);
            i--, j--;
        }
        else {
            if (d[i-1][j] == d[i][j])
                i--;
            else
                j--;
        }
    }
    fout << d[m][n] << "\n";
    for (vector <int> :: reverse_iterator it = sol.rbegin(); it != sol.rend(); ++it)
        fout << a[*it] << " ";
}
