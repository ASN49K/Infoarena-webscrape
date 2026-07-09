#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
int m, n;
int A[1025], B[1025], mat[1025][1025];
int subs[1025];

int main() {
    f >> m >> n;
    for (int i = 1; i <= m; i++)
        f >> A[i];
    for (int i = 1; i <= n; i++)
        f >> B[i];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i] == B[j])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
        }
    }

    cout << mat[m][n] << endl;

    int k = 0;
    for (int i = m, j = n; i >= 1 && j >= 1;) {
        if (A[i] == B[j])
            subs[++k] = A[i];
        if (mat[i-1][j] > mat[i][j-1])
            i--;
        else
            j--;
    }

    for (; k; k--)
        cout << subs[k] << ' ';
    cout << endl;
}
