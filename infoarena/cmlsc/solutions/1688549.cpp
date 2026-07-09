// Cel mai Lung Subsir Comun
#include <fstream>
#include <algorithm>
using namespace std;

const int Dim = 1024;
int a[Dim], b[Dim], n, m, t[Dim],x=0;
int c[Dim][Dim]; // c[i][j] - lungimea celui mai lung subsir comun
                 // in intervalele a[1..i] si b[1..j]
void Read();
int Cmlsc(); // returneaza valoare cmlsc

int main()
{
    Read();

    ofstream fout("cmlsc.out");
    fout << Cmlsc() << '\n';
    for (int i=n, j=m; i;)
    {
        if (a[i]==b[j])
        {
            t[++x]=a[i];
            i--;
            j--;
        }
        else
            if(c[i-1][j]<c[i][j-1])
                j--;
            else
                i--;

    }
    for (int i=x; i>=1; i--)
        fout << t[i] << ' ';
    fout.close();

    return 0;
}

int Cmlsc()
{
    for (int i = 1; i <= n; ++i)
        c[i][0] = 0;
    for (int j = 1; j <= m; ++j)
        c[0][j] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if ( a[i] == b[j] )
            {
                c[i][j] = 1 + c[i - 1][j - 1];
            }

            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
    return c[n][m];
}

void Read()
{
    ifstream fin("cmlsc.in");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int j = 1; j <= m; ++j)
        fin >> b[j];

    fin.close();
}
