//cel mai lung subsir comun
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int lim = 1025;

int n,a[lim],b[lim],m;
int matrice[lim][lim];

int main()
{
    fin >> n >> m;
    for (int i=1;i<=n;i++)
        fin >> a[i];
    for (int i=1;i<=m;i++)
        fin >> b[i];
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (b[i] == a[j])
            {
                matrice[i][j] = matrice[i-1][j-1] + 1;
            }
            else matrice[i][j] = max(matrice[i-1][j],matrice[i][j-1]);
        }
    }
    fout << matrice[m][n] << "\n";
    int k = 0;
    int i = m;
    int j = n;
    while (i!=1 && j!=1)
    {
        if (matrice[i][j] == matrice[i][j-1])
            j--;
        else
        {
            k++;
            b[k] = a[j];
            i--;
            j--;
        }
    }
    for (int i=k;i>=1;i--)
        fout << b[i] << " ";
    return 0;
}
