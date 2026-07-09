#include <fstream>
#define maxim(a, b) ((a > b) ? a : b)

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int MAX = 1030;
int m, n;
int a[MAX], b[MAX], aux[MAX][MAX], sir[MAX];

void citire() {
    int i, j;

    fin >> m >> n;
    for (i = 1; i <= m; i++)
        fin >> a[i];
    for (j = 1; j <= n; j++)
        fin >> b[j];
}

int main() {
    int i, j, k = 0;

    citire();

    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            if (a[i] == b[j])
                aux[i][j] = aux[i - 1][j - 1] + 1;
            else
                aux[i][j] = maxim(aux[i - 1][j], aux[i][j - 1]);

    for (i = m, j = n; i, j; )
        if (a[i] == b[j]) {
            sir[++k] = a[i];
            i--;
            j--;
        } else if (aux[i - 1][j] < aux[i][j - 1])
            j--;
        else 
            i--;

    fout << k << '\n';
    for (i = k; i >= 1; i--)
        fout << sir[i] << ' ';

    fin.close();
    fout.close();

    return 0;
}