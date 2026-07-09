#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int m, n, a[1026], b[1026], v[1026][1026], lmax;
vector<int> aux;
///v[i][j] - cea mai lunga secventa comuna din primele i elemente din a si primele j  elemente din b

int main()
{
    fin >> m >> n;
    for (int i = 1; i <= m; i++)
        fin >> a[i];
    for (int i = 1; i <= n; i++)
        fin >> b[i];

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i==1 && j==1) v[i][j] = 0;
            else if (a[i]==b[j]) v[i][j] = v[i-1][j] + 1;
            else if (a[i] != b[j]) v[i][j] = max(v[i-1][j], v[i][j-1]);
        }
    }
    fout << v[m][n] << "\n";
    while (m && n)
    {
        if (a[m]==b[n])
        {
            aux.push_back(a[m]);
            m--; n--;
        }
        else if (v[m-1][n] < v[m][n-1]) n--;
        else m--;
    }
    for (int i = aux.size() - 1; i >= 0; i--)
        fout << aux[i] << " ";
    fin.close();
    fout.close();
    return 0;
}
