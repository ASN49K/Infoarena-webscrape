# include <fstream>
# include <vector>
# include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAXN = 1030;
vector<int> SOL;
int A[MAXN], B[MAXN], D[MAXN][MAXN];
int n, m;

int main() {
    int i, j;
    fin >> n >> m;
    for (i=1; i<=n; ++i) fin >> A[i];
    for (i=1; i<=m; ++i) fin >> B[i];

    D[1][1] = 1;
    for (i=1; i<=n; ++i) {
        for (j=1; j<=m; ++j) {
            if (A[i] == B[j]) {
                D[i][j] = 1 + D[i-1][j-1];
            } else
                D[i][j] = max(D[i][j-1], D[i-1][j]);
        }
    }

    fout << D[n][m] << "\n";

    i = n, j = m;
    while (i) {
        if (A[i] == B[j]) {
            SOL.push_back(A[i]);
            --i, --j;
        } else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
    }

    reverse(SOL.begin(), SOL.end());
    for (i=0; i<SOL.size(); ++i)
        fout << SOL[i] << " ";

    return 0;
}
