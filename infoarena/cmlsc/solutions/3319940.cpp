#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short *CitesteVector(short n)
{
    short *v = nullptr;
    v = new short[n];
    short i;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    return v;
}

void AfiseazaVector(short *v, short n)
{
    short i;
    for (i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}

char **CreareCMSLC(short *X, short m, short *Y, short n)
{
    short i, j;
    char **b = new char *[m+1];
    short **c = new short *[m+1];
    for (i = 0; i <= m; i++)
    {
        b[i] = new char[n+1];
        c[i] = new short[n+1];
    }
    for (i = 1; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for (j = 0; j <= n; j++)
    {
        c[0][j] = 0;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (X[i-1] == Y[j-1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'd';
            }
            else
            {
                if (c[i - 1][j] > c[i][j - 1])
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 'n';
                }
                else
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 'v';
                }
            }
        }
    }
    fout << c[m][n] << endl;
    for (i = 0; i <= m; i++)
    {
        delete[] c[i];
    }
    delete[] c;
    return b;
}

void AfisareCMLSC(char **b, short *X, short i, short j)
{
    if (0 == i || 0 == j)
    {
        return;
    }
    else
    {
        if ('d' == b[i][j])
        {
            AfisareCMLSC(b, X, i - 1, j - 1);
            fout << X[i-1] << ' ';
        }
        else
        {
            if ('n' == b[i][j])
            {
                AfisareCMLSC(b, X, i - 1, j);
            }
            else
            {
                AfisareCMLSC(b, X, i, j - 1);
            }
        }
    }
}

int main(void)
{
    short M, N, i;
    short *A = nullptr, *B = nullptr;
    char **b = nullptr;
    fin >> M >> N;
    A = CitesteVector(M);
    B = CitesteVector(N);
    b = CreareCMSLC(A, M, B, N);
    AfisareCMLSC(b, A, M, N);
    for (i = 0; i <= M; i++)
    {
        delete[] b[i];
    }
    delete[] b;
    delete[] A;
    delete[] B;
    return 0;
}