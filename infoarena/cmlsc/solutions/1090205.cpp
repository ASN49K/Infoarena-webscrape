#include <fstream>
#define NMAX 1029

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[NMAX],b[NMAX];
int LCS[NMAX][NMAX];

void citire();
void pd();
void afisare();

int main()
{
    citire();
    pd();
    afisare();
    return 0;
}

void afisare()
{
    int i,j;
    fout << LCS[1][1] << '\n';
    i=1;j=1;
    while(i!=n+1 && j!=m+1)
    {
        if(a[i]==b[j])
        {
            fout << a[i] << ' ';
            i++;
            j++;
        }
        else
        {
            if(LCS[i][j]==LCS[i+1][j])
                i++;
            else j++;
        }
    }
    fout << '\n';
}

void citire()
{
    int i;
    fin >> n >> m;
    for(i=1;i<=n;i++)
        fin >> a[i];
    for(i=1;i<=m;i++)
        fin >> b[i];
}

void pd()
{
    int i,j;
    for(i=n;i>0;i--)
        for(j=m;j>0;j--)
            if(a[i]==b[j])
                LCS[i][j]=1+LCS[i+1][j+1];
            else
            if(LCS[i][j+1]> LCS[i+1][j])
                LCS[i][j]=LCS[i][j+1];
            else
                LCS[i][j]=LCS[i+1][j];
}
