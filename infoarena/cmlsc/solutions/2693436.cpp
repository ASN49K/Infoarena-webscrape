#include <fstream>
#define N 1030
using namespace std;
ifstream fin("cmslc.in");
ofstream fout("cmslc.out");

int n, m, a[N], b[N];
int PD[N][N], scm[N];

void Citire()
{
    int i;
    fin >> n >> m;
    for(i=1; i<=n; i++)
        fin >> a[i];
    for(i=1; i<=m; i++)
        fin >> b[i];

}

void ProgramareDinamica()
{
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
           if(a[i]==b[j])
             PD[i][j]=1+PD[i-1][j-1];
           else
              PD[i][j]=max(PD[i-1][j],PD[i][j-1]);

}

void Afisare()
{
    fout <<PD[n][m]<<"\n";
    int i=n, j=m, k=0;
    while(i>=1 && j>=1)
         if(a[i]==b[j])
         {
             scm[++k]=a[i];
             i--;
             j--;
         }
         else if(PD[i][j]==PD[i][j-1]) j--;
         else if(PD[i][j]==PD[i-1][j]) i--;

    for(i=k; i>=1; i--)
        fout << scm[i] <<" ";
}

int main()
{
     Citire();
     ProgramareDinamica();
     Afisare();
    return 0;
}
