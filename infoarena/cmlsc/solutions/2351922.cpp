#include <iostream>
#include <fstream>
#define NMAX 1024
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short int a[NMAX],b[NMAX],Sol[NMAX][NMAX],Mut[NMAX][NMAX],af[NMAX];
int main()
{
    int n,m,i,j;
    fin>>n>>m;
    for(i=1;i<=n;++i)
        fin>>a[i];
    for(j=1;j<=m;++j)
        fin>>b[j];
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
            if(a[i]==b[j])
        {
            Sol[i][j]=Sol[i-1][j-1]+1;
            Mut[i][j]=1;
        }
        else {
            if(Sol[i-1][j]>Sol[i][j-1]) Sol[i][j]=Sol[i-1][j],Mut[i][j]=2;
            else Sol[i][j]=Sol[i][j-1],Mut[i][j]=3;
        }
    }
    fout<<Sol[n][m]<<"\n";
    i=n;
    j=m;
    int k=0;
    while(Mut[i][j])
    {
        if(Mut[i][j]==1) af[++k]=a[i],i--,j--;
        else if(Mut[i][j]==2) i--;
        else if(Mut[i][j]==3) j--;
    }
    for(i=k;i>=1;i--)
        fout<<af[i]<< " ";
    return 0;
}
