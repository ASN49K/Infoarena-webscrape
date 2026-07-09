#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int matrice[300][300];
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
    int n, m, a[300],b[300];

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
    fout<<matrice[n][m]<<'\n';
    afisare(n,m,a,b);

    return 0;
}
