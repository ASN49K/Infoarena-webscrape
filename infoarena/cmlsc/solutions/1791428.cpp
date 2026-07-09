#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define LMAX 1025

int M, N, A[LMAX], B[LMAX], dmax[LMAX][LMAX], sol[LMAX], index;

void citire()
{
    fin >> M >> N;
    for (int i = 1; i <= M; i++)
        fin >> A[i];
    for (int i = 1; i <= N; i++)
        fin >> B[i];
}

int maxval(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    else if (b > a && b > c)
        return b;
    return c;
}
/*
void aff()
{
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            fout << dmax[i][j] << " ";
        }
        fout << endl;
    }
    fout << "------------\n\n";
}*/

void set_lmax()
{
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (A[i] == B[j])
            {
                dmax[i][j] = dmax[i - 1][j - 1] + 1;
            }
            else
            {
                dmax[i][j] = maxval(dmax[i][j], dmax[i - 1][j], dmax[i][j - 1]);
            }
             //fout << "i: " << i << " j: " << j << " A[i] = "  << A[i] << " B[j] = " << B[j] <<endl;
            //aff();
        }
    }
}

int main()
{
    citire();
    set_lmax();
    int i = M, j = N;
    index = dmax[M][N];
    while (i && j)
    {
        if (A[i] == B[j])
        {#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define LMAX 1025

int M, N, A[LMAX], B[LMAX], dmax[LMAX][LMAX], sol[LMAX], index;

void citire()
{
    fin >> M >> N;
    for (int i = 1; i <= M; i++)
        fin >> A[i];
    for (int i = 1; i <= N; i++)
        fin >> B[i];
}

int maxval(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    else if (b > a && b > c)
        return b;
    return c;
}
/*
void aff()
{
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            fout << dmax[i][j] << " ";
        }
        fout << endl;
    }
    fout << "------------\n\n";
}*/

void set_lmax()
{
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (A[i] == B[j])
            {
                dmax[i][j] = dmax[i - 1][j - 1] + 1;
            }
            else
            {
                dmax[i][j] = maxval(dmax[i][j], dmax[i - 1][j], dmax[i][j - 1]);
            }
             //fout << "i: " << i << " j: " << j << " A[i] = "  << A[i] << " B[j] = " << B[j] <<endl;
            //aff();
        }
    }
}

int main()
{
    citire();
    set_lmax();
    int i = M, j = N;
    index = dmax[M][N];
    while (i && j)
    {
        if (A[i] == B[j])
        {
            sol[index] = A[i];
            index--;
            i--; j--;
        }
        else if (dmax[i-1][j] < dmax[i][j-1])
            j--;
        else
            i--;
    }
    fout << dmax[M][N] << endl;
    for (int i = 1; i <= dmax[M][N]; i++)
        fout << sol[i] << " ";
    return 0;
}

            sol[index] = A[i];
            index--;
            i--; j--;
        }
        else if (dmax[i-1][j] < dmax[i][j-1])
            j--;
        else
            i--;
    }
    fout << dmax[M][N] << endl;
    for (int i = 1; i <= dmax[M][N]; i++)
        fout << sol[i] << " ";
    return 0;
}

