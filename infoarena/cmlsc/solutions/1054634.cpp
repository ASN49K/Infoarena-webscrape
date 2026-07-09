#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, i, j, A[1030], B[1030], C[1030][1030];

void show(int n, int m) {
    if (n==0 || m==0) return;
    if (A[n]==B[m]) {
        show(n-1, m-1);
        g << A[n] << ' ';
    }
    else if (C[n][m] == C[n-1][m]) show(n-1, m);
    else if (C[n][m] == C[n][m-1]) show(n, m-1);
}

int main() {
    f >> n >> m;
    for (i=1; i<=n; i++)
        f >> A[i];

    for (i=1; i<=m; i++)
        f >> B[i];

    for (i=0; i<=n; i++)
        C[i][0] = C[0][i] = 0;

    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            C[i][j] = (A[i] == B[j]) ? C[i-1][j-1] + 1 : max(C[i-1][j], C[i][j-1]);

    g << C[n][m] << endl;
    show(n, m);
}
