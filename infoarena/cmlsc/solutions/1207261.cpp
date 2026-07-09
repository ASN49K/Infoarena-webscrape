#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define Dim 1025

int m, n;
int a[Dim], b[Dim];
int c[Dim][Dim];    // c[i][j] = c.m.l.s.comun intre primele i elem din a si primele j din b

void Read();
int Dynamic();
void Write(int i, int j);

int main()
{
    Read();
    fout << Dynamic() << '\n';
    Write(n, m);
    fout << '\n';
    fin.close();
    fout.close();
}

void Write(int i, int j)
{
    if ( !i || !j ) return;
    if ( a[i] == b[j] )
    {
        Write(i - 1, j - 1);
        fout << a[i] << ' ';
        return;
    }
    if ( c[i - 1][j] > c[i][j - 1] )
        Write(i - 1, j);
    else
        Write(i, j - 1);
}

int Dynamic()   // O(n^2)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if  ( a[i] == b[j] )
                c[i][j] = 1 + c[i - 1][j - 1];
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
    return c[n][m];
}

void Read()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int j= 1; j <= m; ++j)
        fin >> b[j];
}






