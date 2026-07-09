#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1100], b[1100], cm[1100][1100], n, m;

void read() {

    fin >> n >> m;
    for(int i = 1; i <= n; i++) {

        fin >> a[i];

    }
    for(int i = 1; i <= m; i++) {

        fin >> b[i];

    }

}

void printSolution(int i, int j, int x) {

    if (x == 0) {

        return;

    }
    if (a[i] == b[j]) {

        printSolution(i - 1, j - 1, x - 1);
        fout << a[i] << ' ';
        return;

    }
    if (cm[i - 1][j] > cm[i][j - 1]) {

        printSolution(i - 1, j, x);
        return;

    }
    printSolution(i, j - 1, x);
}
void cmlsc() {

    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j <= m; ++j) {

            if (a[i] == b[j]) {

                cm[i][j] = cm[i - 1][j - 1] + 1;

            }
            else {

                cm[i][j] = max(cm[i][j - 1], cm[i - 1][j]);

            }

        }

    }
    fout << cm[n][m] << '\n';
    int x = cm[n][m];
    printSolution(n, m, x);

}
int main()
{
    read();
    cmlsc();

    return 0;
}
