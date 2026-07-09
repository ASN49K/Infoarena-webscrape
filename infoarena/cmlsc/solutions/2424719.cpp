#include <iostream>
#include <fstream>
#include <vector>
#define nmax 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[nmax], b[nmax], n, m, c[nmax][nmax], k, sir[nmax];

void CMLSC()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int j = 1; j <= m; j++)
        fin >> b[j];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
            {
                c[i][j] = 1 + c[i-1][j-1];
            }
            else
            {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }

    int i = n, j = m;
    while(i)
    {
        if(a[i] == b[j])
        {
            sir[++k] = a[i];
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

    fout << k << '\n';
    for(int i = k; i >= 1; i--)
        fout << sir[i] << " ";
}

int main()
{
    CMLSC();
    return 0;
}
