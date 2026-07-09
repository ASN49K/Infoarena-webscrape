#include <fstream>
#define NMAX 1024

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void citire();
void pd();
int max(int x, int y);
void afisare();

int n, m;
int lcs[NMAX][NMAX];//lungimea celui mai lung subsir comun
int op[NMAX][NMAX];//cazurile 1, 2, 3
int a[NMAX], b[NMAX];

int main()
{
    citire();
    pd();
    afisare();
    return 0;
}

void citire()
{
    int i,j;
    fin>>n>>m;

    for(i=1;i<=n;i++)
    fin>>a[i];

    for(j=1;j<=m;j++)
    fin>>b[j];
}

void pd()
{
    int i, j;
    //bottom-up!!!
    for(i=n-1;i>=0;i++)
    for(j=m-1;j>=0;j++)
    if(a[i]==b[j])
    {
        lcs[i][j]=1+lcs[i+1][j+1];
        op[i][j]=1;
    }
    else
    {
        if(lcs[i+1][j]<lcs[i][j+1])
        {
            lcs[i][j]=lcs[i][j+1];
            op[i][j]=3;
        }
        else
        {
            lcs[i][j]=1+lcs[i+1][j];
            op[i][j]=2;
        }
    }
}

void afisare()
{
    int i,j;
    i=j=0;
    fout<<lcs[0][0]<<'\n';

    while(i<n && j<m)
    if(op[i][j]==1)
    {
        fout<<a[i]<<' ';
        i++;
        j++;
    }
    else
    {
        if(op[i][j]==2)
        j++;
        else
        i++;
    }
}
