#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

// Functie Helper: Maxim
short max(short a, short b)
{ return a > b ? a : b; }
// Matricea solutiei
short lcs[1025][1025];
// Afisarea solutiei
void solutie(short x[], short y[], short i, short j)
{
    if (i != 0 && j != 0) {
        if (x[i] == y[j]) { solutie(x, y, i-1, j-1); out << x[i] << ' '; }
        else if (lcs[i][j-1] > lcs[i-1][j]) solutie(x, y, i, j-1);
        else solutie(x, y, i-1, j);
    }
}

int main()
{
    short x[1025], y[1025], m, n;
    // Citirea datelor
    in >> m >> n;
    for (short i = 1; i <= m; i++) in >> x[i];
    for (short i = 1; i <= n; i++) in >> y[i];
    // Algoritmul LCS
    for (short i = 1; i <= m; i++) {
        for (short j = 1; j <= n; j++) {
            if (x[i] == y[j]) lcs[i][j] += 1 + lcs[i-1][j-1];
            else lcs[i][j] += max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    out << lcs[m][n] << '\n';
    solutie(x, y, m, n);

    return 0;
}
