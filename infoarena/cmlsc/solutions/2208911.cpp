#include <iostream>
#include <fstream>
#define dMAX (1 << 10)

using namespace std;

int n, m;
int arr1[dMAX + 2], arr2[dMAX + 2];
int LCSMatrix[dMAX + 2][dMAX + 2];

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

void FindLCS(int x, int y) {
    if (x == 0 || y == 0) return;
    if (LCSMatrix[x][y] == LCSMatrix[x][y - 1]) {
        FindLCS(x, y - 1);
    } else if (LCSMatrix[x][y] == LCSMatrix[x - 1][y - 1]) {
        FindLCS(x - 1, y);
    } else {
        FindLCS(x - 1, y - 1);
        fout << arr1[y] << ' ';
    }
}

int main()
{
    int i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++) fin >> arr1[i];
    for (i = 1; i <= m; i++) fin >> arr2[i];
    ProcessMatrix();
    fout << LCSMatrix[m][n] << '\n';
    /*for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            cout << LCSMatrix[i][j] << ' ';
        }
        cout << '\n';
    }*/
    FindLCS(m, n);
    return 0;
}
