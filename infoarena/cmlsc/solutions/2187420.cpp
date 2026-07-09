#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short a[1030], b[1030], c[1030];

int main()
{
    int n, m, k = 1;
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int j = 1; j <= m; j++)
        fin >> b[j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                c[k] = a[i];
                k++;
            }
        }
    fout << k - 1 << '\n';
    for (int i = 1; i < k; i++)
        fout << c[i] << ' ';
    fout << '\n';
    return 0;
}
