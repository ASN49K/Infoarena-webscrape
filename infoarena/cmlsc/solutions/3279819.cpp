#include <iostream>
#include<fstream>
using namespace std;
const int NMAX=1025;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[NMAX],b[NMAX],
    c[NMAX][NMAX],
    s[NMAX];

void citire()
{
    fin>>m>>n;
    for(int i=1; i<=m; i++)
        fin>>a[i];
    for(int i=1; i<=n; i++)
        fin>>b[i];
}

void calcul()
{
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
}

void generare()
{
    int i=m,j=n;
    int k=c[m][n];
    while(i>0&&j>0)
        if(a[i]==b[j])
        {
            s[k]=a[i];
            i--,j--,k--;
        }
        else if(c[i-1][j]>=c[i][j-1])
            i--;
        else
            j--;
}

void afisare()

{
    int maxx=c[m][n];
    fout<<maxx<<'\n';
    for(int i=1; i<=maxx; i++)
        fout<<s[i]<<' ';
}
int main()
{
    citire();
    calcul();
    generare();
    afisare();
    fin.close();
    fout.close();
    return 0;
}
