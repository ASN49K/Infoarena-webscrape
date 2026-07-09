#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMax 1024

int n,m, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst,i,j;

int main(void)
{
    fin >> m >> n;
    for (int i = 1; i <= m; i++)
        fin >> A[i];
    for (int i = 1; i <= n; i++)
        fin >> B[i];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i - 1][j - 1];
            else
                D[i][j] = maxim(D[i - 1][j], D[i][j - 1]);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            cout << D[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= m; i++) {
            cout << A[i]<< " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << B
            [i] << " ";
    }
    cout << endl;


    i = m, j = n;
    while (i >= 1)
        if (A[i] == B[j]) {
            sir[++bst] = A[i];
            --i;
            --j;
        }
        else if (D[i - 1][j] < D[i][j - 1])
            --j;
        else
            --i;
    cout << bst <<endl;
    for (i = bst; i; --i)
        cout << sir[i] << " ";
    return 0;
}