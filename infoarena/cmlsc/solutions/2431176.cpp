#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int m,n,p,a[1025],b[1025],v[1025];
int matrice[1025][1025];
void citire()
{
    fin>>m>>n;
    for (int i=1; i<=m; i++)
        fin>>a[i];
    for (int i=1; i<=n; i++)
        fin>>b[i];
    fin.close();
}
void p_dinamica()
{
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if (a[i]==b[j])
                matrice[i][j]=matrice[i+1][j-1]+1;
            else
                if (matrice[i-1][j]>matrice[i][j-1])
                    matrice[i][j]=matrice[i-1][j];
                else
                    matrice[i][j]=matrice[i][j-1];
}
void prelucrare(int i,int j)
{
    if (matrice[i][j])
        if (a[i]==b[j])
        {
            prelucrare(i-1,j-1);
            v[++p]=a[i];
        }
        else
            if (matrice[i][j]==matrice[i-1][j])
                prelucrare(i-1,j);
            else
                if (matrice[i][j]==matrice[i][j-1])
                    prelucrare(i,j-1);
}
void afisare()
{
    fout<<p<<'\n';
    for (int i=1; i<=p; i++)
        fout<<v[i]<<" ";
    fout.close();
}
int main()
{
    citire();
    p_dinamica();
    prelucrare(m,n);
    afisare();
    return 0;
}
