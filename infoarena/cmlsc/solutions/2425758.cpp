#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1001], b[1001], c[1001][1001];

void afisare()
{
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(a[i] == b[j])
                fout << a[i] <<' ';
}
int main()
{
    fin >> m >> n;

    int i, j;

    for(i = 0; i < m; i++) fin >> a[i];
    for(i = 0; i < n; i++) fin >> b[i];

        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(a[i] == b[j])
                    c[i][j] = 1 + c[i-1][j-1];
                else
                    c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }

    fout << c[m-1][n-1] << endl;
    afisare();
    return 0;
}
