#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int dim=1029;

int n, m, a[dim], b[dim], x[dim][dim], rez[dim], k;

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];
    for(int i=1; i<=m; i++)
        fin>>b[i];

    fin.close();

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        if(a[i]==b[j])
        x[i][j]=x[i-1][j-1]+1;
        else x[i][j]=max(x[i-1][j], x[i][j-1]);

    int lmax=x[n][m];

    fout<<lmax<<'\n';

    int i=n, j=m;

    while(i>=1 && j>=1)
            if(a[i]==b[j])
            rez[++k]=a[i], i--, j--;
            else if(x[i-1][j]<x[i][j-1])
                j--;
            else i--;

    for(int i=k; i>=1; i--)
        fout<<rez[i]<<' ';


    fout.close();

    return 0;
}
