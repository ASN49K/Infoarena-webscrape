#include <iostream>
#include <fstream>

#define Nmax 1024
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

char c;
short n,m,i,j;
short v1[Nmax+1],v2[Nmax+1];
short l[Nmax+1][Nmax+1];
short lcs[Nmax];
int main()
{

    fin>>n>>m;
    for (i=1;i<=n;i++)
        fin>>v1[i];
    for (i=1;i<=m;i++)
        fin>>v2[i];

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (v1[i]==v2[j])
                l[i][j]=l[i-1][j-1]+1;
            else
                l[i][j]=max(l[i-1][j], l[i][j-1]);
        }
    }
    fout<<l[n][m]<<'\n';
    i=n;
    j=m;
    while (i>0 && j>0)
    {
        if (v1[i]==v2[j])
        {
            lcs[l[i][j]-1]=v1[i];
            i--;
            j--;

        }
        else if (l[i-1][j]<l[i][j-1]) j--;
        else i--;
    }
    for (i=0;i<l[n][m];i++)
        fout<<lcs[i]<<' ';
    return 0;
}
