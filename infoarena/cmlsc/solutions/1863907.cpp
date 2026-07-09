#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, MAX;
int x;
int A[1030];
int B[1030];
int C[2100];

int main()
{
    fin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fin >> x;
        A[i] = x;
    }

    for (int i = 1; i <= m; i++) {
        fin >> x;
        B[i] = x;
    }

    int i = 1;
    int j = 1;

    while (i <= n && j <= m) {
        if (A[i] == B[j]) {
            fout << A[i] << ' ';
            i++;
            j++;
        }
        else
            if (A[i] < B[j])
                i++;
            else
                j++;
    }

    if (i > n)
        i--;
    if (j > m)
        j--;

    if (i == j) {
        return 0;
    }

    if (i == n)
        for (; j <= m; j++)
            if (B[j] == A[i])
                fout << B[j] << ' ';

    if (j == m)
        for (; i <= n; i++)
            if (A[i] == B[j])
                fout << A[i] << ' ';


    return 0;
}
