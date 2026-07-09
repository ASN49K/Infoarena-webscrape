#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1025], b[1025], mat[1025][1025], lmax;

void citire()
{
    fin >> n >> m;
    for(int i = 0; i < n; i++)
        fin >> a[i];
    for(int i = 0; i < m; i++)
        fin >> b[i];
}

int max(int a, int b, int c)
{
    int maxi = -1;
    if(a > maxi)
        maxi = a;
    if(b > maxi)
        maxi = b;
    if(c > maxi)
        maxi = c;
    return maxi;
}

void ind_max(int i1, int i2, int i3, int i4, int i5, int i6, int &imax1, int &imax2)
{
    int maxi = -1;
    imax1 = -1;
    imax2 = -1;
    if(i1 >= 0 && i2 >= 0)
    {
        if(mat[i1][i2] > maxi)
        {
            imax1 = i1;
            imax2 = i2;
            maxi = mat[i1][i2];
        }
    }
    if(i3 >= 0 && i4 >= 0)
    {
        if(mat[i3][i4] > maxi)
        {
            imax1 = i3;
            imax2 = i4;
            maxi = mat[i3][i4];
        }
    }
    if(i5 >= 0 && i6 >= 0)
    {
        if(mat[i5][i6] > maxi)
        {
            imax1 = i5;
            imax2 = i6;
            maxi = mat[i5][i6];
        }
    }

}

void constr_mat()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i] == b[j])
                mat[i][j] = mat[i - 1][j - 1] + 1;
            else
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1], mat[i - 1][j - 1]);
            if(mat[i][j] > lmax)
                lmax = mat[i][j];
        }

    }
}

void parcurgere(int i, int j)
{
    if(i < 0 && j < 0)
        return;
    if(a[i] == b[j])
    {
        parcurgere(i - 1, j - 1);
        fout << a[i] << ' ';
    }
    else
    {
        int imax1, imax2;
        ind_max(i - 1, j - 1, i, j - 1, i - 1, j, imax1, imax2);
        parcurgere(imax1, imax2);
    }
}

void afisare()
{
    fout << mat[n - 1][m - 1] << '\n';
    parcurgere(n - 1, m - 1);
}

int main()
{
    citire();
    constr_mat();
    afisare();
    return 0;
}
