#include <iostream>
#include <fstream>
#define dMAX (1 << 10)

using namespace std;

int n, m;
int arr1[dMAX + 2], arr2[dMAX + 2];
int LCSMatrix[dMAX + 2][dMAX + 2];
int LCS[dMAX + 2], idx;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void ProcessMatrix() {
    int i, j;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (arr1[j] == arr2[i]) {
                LCSMatrix[i][j] = LCSMatrix[i - 1][j - 1] + 1;
            } else
                LCSMatrix[i][j] = max(LCSMatrix[i - 1][j], LCSMatrix[i][j - 1]);
        }
    }
}

void FindLCS() {
    int i, j;
    i = m, j = n;
    while (i && j) {
        if (LCSMatrix[i][j] == LCSMatrix[i - 1][j]) {
            i--;
        } else if (LCSMatrix[i][j] == LCSMatrix[i][j - 1]) {
            j--;
        } else if (LCSMatrix[i][j] == LCSMatrix[i - 1][j - 1] + 1) {
            LCS[++idx] = arr1[j];
            i--, j--;
        }
    }
    for (i = idx; i >= 1; i--) fout << LCS[i] << ' ';
}

int main()
{
    int i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++) fin >> arr1[i];
    for (i = 1; i <= m; i++) fin >> arr2[i];
    ProcessMatrix();
    fout << LCSMatrix[m][n] << '\n';
    FindLCS();
    return 0;
}
