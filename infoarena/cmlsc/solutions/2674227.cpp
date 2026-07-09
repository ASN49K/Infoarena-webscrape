#include <iostream>
#include <fstream>

using namespace std;
int A[1025];
int B[1025];
int matrix[1025][1025];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int cmlscLength(int m, int n) {
    for (int i = 0; i <= m; ++i) {
        matrix[i][0] = 0;
    }
    for (int j = 0; j <= n; ++j) {
        matrix[0][j] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i] == B[j]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = max(matrix[i][j - 1], matrix[i - 1][j]);
            }
        }
    } return matrix[m][n];
}

void traceback(int m, int n) {
    if (matrix[m][n] == 0) return;
    if (A[m] == B[n]) {
        traceback(m - 1, n - 1);
        fout << A[m] << " ";
    } else if (matrix[m][n - 1] > matrix[m - 1][n]) {
              traceback(m, n - 1);
    } else {
        traceback(m - 1, n);
    }
}

int main()
{
    int m, n, length;
    fin >> m >> n;

    for (int i = 1; i <= m; ++i) {
        fin >> A[i];
    }
    for (int i = 1; i <= n; ++i) {
        fin >> B[i];
    }

    length = cmlscLength(m, n);
    fout << length << "\n";
    traceback(m, n);

    return 0;
}
