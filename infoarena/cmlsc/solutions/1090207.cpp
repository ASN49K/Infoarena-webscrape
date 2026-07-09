#include <fstream>
#define dmax 102

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m;
int a[dmax], b[dmax], LCS[dmax][dmax];

void citire();
void pd();
void afisare();

int main()
{
    citire();
    pd();
    afisare();
    fout.close();
    return 0;
}
void citire()
{
    fin>>n>>m;
    for (int i=1; i<=n; i++)
        fin>>a[i];
    for (int j=1; j<=m; j++)
        fin>>b[j];
}
void pd()
{
    for (int i=n; i>0; i--)
        for (int j=m; j>0; j--)
            if (a[i]==b[j])
                LCS[i][j]=1+LCS[i+1][j+1];
            else
                if (LCS[i][j+1]>LCS[i+1][j])
                    LCS[i][j]=LCS[i][j+1];
                else
                    LCS[i][j]=LCS[i+1][j];
}
void afisare()
{
    int i, j;
    fout<<LCS[1][1]<<'\n';
    i=j=1;
    while (i<=n&&j<=m)
        if (a[i]==b[j])
        {
            fout<<a[i]<<' ';
            i++;
            j++;
        }
        else
            if (LCS[i][j]==LCS[i+1][j])
                i++;
            else
                j++;
    fout<<'\n';
}
