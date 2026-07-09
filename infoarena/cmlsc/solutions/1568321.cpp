#include <fstream>
#define NN 1005

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, x[NN], y[NN], mat[NN][NN];

void Citire()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> x[i];
    for (int j = 1; j <= m; j++)
        fin >> y[j];
}

void CreareMatrice()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i] == y[j])
                mat[i][j] = 1 + mat[i-1][j-1];
            else
                mat[i][j] = max(mat[i][j-1], mat[i-1][j]);
        }
    }
}

void back(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    else if (x[i] == y[j])
    {
        back(i-1, j-1);
        fout << x[i] << " ";
    }
    else
    {
        if (mat[i][j-1] > mat[i-1][j])
            back(i, j-1);
        else
            back(i-1, j);
    }
}


int main()
{
    Citire();
    CreareMatrice();
    fout << mat[n][m] << endl;
    back(n, m);
    return 0;
}
