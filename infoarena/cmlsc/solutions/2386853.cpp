#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int matrice[2000][2000];
void afisare(int i, int j, int a[], int b[])
{
    if(matrice[i][j]!=0)
    {
        if(matrice[i-1][j]==matrice[i][j-1]&&a[i]==b[j])
    {
        afisare(i-1,j-1,a,b);
        fout<<a[i]<<" ";
    }
    else switch(matrice[i-1][j]>matrice[i][j-1])
    {
    case 1:
        afisare(i-1,j,a,b);
    case 0:
        afisare(i,j-1,a,b);
    }
    }

}
int main()
{
    int n, m, a[2000],b[2000];

    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        fin>>b[i];
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            matrice[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j])
        {
            matrice[i][j]=matrice[i-1][j-1]+1;
        }
        else
        {
            matrice[i][j]=max(matrice[i-1][j],matrice[i][j-1]);
        }
    }
    int f[20000];
    int nax=0;
    int i,j;
    i=n;
    j=m;
    for(i=n,j=m;i;)
        if(a[i]==b[j]) f[++nax]=a[i],i--,j--;
        else if(matrice[i-1][j]<matrice[i][j-1]) j--;
        else i--;
    fout<<matrice[n][m]<<'\n';
    for (int i=nax;i>0;i--)
        fout<<f[i]<<' ';

    return 0;
}
