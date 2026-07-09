#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, maxLenght;
int arrA[1050], arrB[1050], mat[1050][1050], sollution[1050];

int maxim(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

int main()
{
    cin >> m >> n;

    for (int i = 1; i <= m; i++)
        cin >> arrA[i];

    for (int i = 1; i <= n; i++)
        cin >> arrB[i];

    for (int i = 0; i <= m; i++)
        mat[i][0] = 0;

    for (int j = 0; j <= n; j++)
        mat[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arrA[i] == arrB[j])
                mat[i][j] = 1 + mat[i - 1][j - 1];
            else
                mat[i][j] = maxim(mat[i - 1][j], mat[i][j - 1]);
        }
    }

    cout << mat[m][n] << "\n";

    int x = 0;

    while (m > 0 && n > 0)
    {
        if (arrA[m] == arrB[n])
        {
            sollution[++x] = arrA[m];
            m--;
            n--;
        }
        else
        {
            if (mat[m][n] == mat[m - 1][n])
                m--;
            else if (mat[m][n] == mat[m][n - 1])
                n--;
        }
    }

    for (int i = x; i >= 1; i--)
        cout << sollution[i] << " ";

    fin.close();
    fout.close();

    return 0;
}
