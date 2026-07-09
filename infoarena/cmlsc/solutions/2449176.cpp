#include <iostream>
#include<fstream>
#include<vector>
using namespace std;
#define nmax 1024

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int sir1[nmax],sir2[nmax];
int exista[256];
int n,m;
int matrice[nmax][nmax];

int main()
{int i,j;
f>>n>>m;
for(i=1;i<=n;i++)
    f>>sir1[i];
for(i=1;i<=m;i++)
    f>>sir2[i];
for(i=1;i<=m;i++)
    matrice[0][i]=0;
for(i=1;i<=n;i++)
    matrice[i][0]=0;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {if(sir1[i]!=sir2[j])
        matrice[i][j]=max(matrice[i][j-1],matrice[i-1][j]);
    else matrice[i][j]=1+matrice[i-1][j-1];
        }
        int nr=0;
g<<matrice[n][m]<<endl;
int elemente[matrice[n][m]];
i=n;
j=m;
int index=matrice[n][m];
while(i>0 && j>0)
    {
        if(sir1[i]==sir2[j])
        {
            elemente[index]=sir1[i];
            i--;
            j--;
            index--;
        }
        if(matrice[i-1][j]>matrice[i][j-1])
       i--;
        else
            j--;
    }
    for(i=1;i<=matrice[n][m];i++)
        g<<elemente[i]<<" ";


    return 0;
}
