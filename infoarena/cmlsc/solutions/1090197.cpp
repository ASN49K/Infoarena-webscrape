#include <fstream>
#define IN "cmlsc.in"
#define OUT "cmlsc.out"
#define NMAX 1025
using namespace std;

int n,m;
int a[NMAX],b[NMAX];
int lcs[NMAX][NMAX];
void citire()
{
    int i,j;
    ifstream fin(IN);
    fin>>n;
    fin>>m;
    for(i=1; i<=n; i++) fin>>a[i];
    for(i=1; i<=m; i++) fin>>b[i];
}

void pd()
{
    int i,j;
    for(i=n; i>0; i--)
        for(j=m; j>0; j--)
        {
            if(a[i]==b[j])
                lcs[i][j]=1+lcs[i+1][j+1];
            else if(lcs[i][j+1]>lcs[i+1][j])
                lcs[i][j]=lcs[i][j+1];
            else
                lcs[i][j]=lcs[i+1][j];
        }
}

void afisare()
{
    int i,j;
    ofstream fout(OUT);
    fout<<lcs[1][1]<<'\n';
    i=1;
    j=1;
    while(i<=n && j<=m)
    {
        if(a[i]==b[j])
        {
            fout<<a[i]<<' ';
            i++;
            j++;
        }
        else if(lcs[i][j]==lcs[i+1][j])
        {
            i++;
        }
        else j++;

    }
    fout<<'\n';
}

int main()
{
    citire();
    pd();
    afisare();
    return 0;
}
