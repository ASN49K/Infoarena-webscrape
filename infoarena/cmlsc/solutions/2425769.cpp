#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, k, a[1001], b[1001], c[1001][1001], aux[1001];

void afisare()
{
    int i = n, j = m;
    while(i)
    {
        if(a[i] == b[j])
        {
            aux[++k] = a[i];
            i--;
            j--;
        }
        else
        {
            if(c[i-1][j] < c[i][j-1])
                j--;
            else
                i--;
        }
    }

    fout << k << endl;
    for(int i = k; i >= 1; i--)
        fout << aux[i] << ' ';
}

int main()
{
    fin >> n >> m;

    int i, j;

    for(i = 1; i <= n; i++) fin >> a[i];
    for(j = 1; j <= m; j++) fin >> b[j];

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(a[i] == b[j])
                    c[i][j] = 1 + c[i-1][j-1];
                else
                    c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }

    afisare();
    return 0;
}
