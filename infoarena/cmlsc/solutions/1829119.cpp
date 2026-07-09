#include <iostream>
#include <fstream>
#define nmax 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int x[nmax],y[nmax],l[nmax][nmax];
int n,m;
void Citire()
{
    int i;
    fin>>n,m;
    for(i=1;i<=n;i++)
        fin>>x[i];
    for(i=1;i<=m;i++)
        fin>>y[i];
}
void LCS()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
         if(x[i]==y[j]) l[i][j]=1+l[i-1][j-1];
         else l[i][j]=max(l[i][j-1],l[i-1][j]);
}
void Afisare()
{
    int D[nmax],k=0;
    fout<<l[n][m]<<endl;
    int i,j;
    i=n;j=m;
    while(i>0 && j>0)
    {
        if(x[i]==y[j])  D[++k]=x[i],i--,j--;
        else if(l[i][j-1]>l[i-1][j]) j--;
             else i--;
    }
   for(i=k;i>=1;i--) fout<<D[i]<<" ";

}
int main()
{ Citire();
 LCS();
 Afisare();
    return 0;
}
