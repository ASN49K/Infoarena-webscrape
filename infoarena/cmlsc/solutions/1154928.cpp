#include <fstream>
#include <stdio.h>
#define Maxim(a, b) (a>b) ? a : b
#define Nmax 1024
using namespace std;
ofstream fout("cmlsc.out");
FILE *fin=fopen("cmlsc.in", "r");
int a[Nmax], b[Nmax], sir[Nmax], mat[Nmax][Nmax], n, m, nr;

void Citire()
{
    int i;
    fscanf(fin, "%d %d ", &m, &n);
    for(i=1; i<=m; i++)
        fscanf(fin, "%d ", &a[i]);
    for(i=1; i<=n; i++)
        fscanf(fin, "%d ", &b[i]);
}

void Construire()
{
    int i, j;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]==b[j]) mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=Maxim(mat[i-1][j], mat[i][j-1]);
    for(i=m, j=n; i;)
        if(a[i]==b[j]){ sir[++nr]=a[i]; i--; j--;}
        else if(mat[i-1][j] >= mat[i][j-1])
            i--;
        else
            j--;
}

void Afisare()
{
    int i;
    fout<<nr<<'\n';
    for(i=nr; i; i--)
        fout<<sir[i]<<' ';
    fout.close();
}

int main()
{
    Citire();
    Construire();
    Afisare();
    return 0;
}

