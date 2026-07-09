#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1025;

struct matrice
{
    int val, ord;
};

int a[NMAX], b[NMAX], n, m, k, x[NMAX];

matrice mat[NMAX][NMAX];

void afisare()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << mat[i][j].val << ' ' << mat[i][j].ord << "     ";
        }
        cout << '\n';
    }
}

void scrie(int i, int j)
{
    if(i == 0 || j == 0)
        return;
    if(mat[i][j].ord == 1)
    {
        scrie(i - 1, j - 1);

        fout << b[j] << ' ';
    }
    else if(mat[i][j].ord == 2)
    {
        scrie(i - 1, j);
    }
    else
    {
        scrie(i, j - 1);
    }
}

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        fin >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        fin >> b[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i == 1 || j == 1)
            {
                if(a[i] == b[j])
                {
                    mat[i][j].val = 1;
                    mat[i][j].ord = 1;
                }

            }
            else
            {
                if(a[i] == b[j])
                {
                    mat[i][j].val = mat[i - 1][j - 1].val + 1;
                    mat[i][j].ord = 1;
                }
                else
                {
                    mat[i][j].val = max(mat[i - 1][j].val, mat[i][j - 1].val);
                    if(mat[i][j].val == mat[i - 1][j].val)
                    {
                        mat[i][j].ord = 2;
                    }
                    else
                    {
                        mat[i][j].ord = 3;
                    }
                }
            }
        }
    }
    fout << mat[n][m].val << '\n';
    scrie(n, m);


    return 0;
}
