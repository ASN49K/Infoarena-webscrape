#include <iostream>
#include <fstream>
#define N 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int X[N], Y[N], L[N][N];
int n,m;
void Citire()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>X[i];
    for(i=1;i<=n;i++) fin>>Y[i];
}

void LCS()
{
    for(int i=1; i<=n; i++)
        for(int j=1;j<=m;j++)
        if(X[i]==Y[i]) L[i][j]=L[i-1][j-1];
        else L[i][j]=max(L[i][j-1], L[i-1][j]);
}
void Afisare()
{
    int D[N], k=0,i,j;
    fout<< L[n][m]<<endl;
    i=n; j=m;
    while( i>0 && j>0)
    {
        if(X[i]==Y[j])
        {
            D[++k]=X[i];
            i--; j--;
        }
        else if(L[i][j-1]> L[i-1][j]) j--;
            else i--;
    }
    for(i=k; i>=1; i--)
        fout<<D[i]<<" ";
}
int main()
{   Citire();
    LCS();
    Afisare();

    return 0;
}
