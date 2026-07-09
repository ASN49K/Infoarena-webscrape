#include <iostream>
#include <fstream>
#define q 1024
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{int n,m,b[q], a[q],d[q][q],x[q];
    fin>>n;
    fin>>m;
    for (int i=1; i<=n; i++) fin>>a[i];
    for (int i=1; i<=m; i++) fin>>b[i];

    for (int i=1; i<=n; i++ )
    {
        for (int j=1; j<=m; j++ )
            if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
        else d[i][j]=max(d[i-1][j], d[i][j-1]);
    }
    fout<<d[n][m];
    int i=n;
    int j=m;
    while (i && j)
    {
        if (a[i]==b[j]) {x[d[i][j]]=a[n]; i--; j--;}
        else if(d[i][j]==d[i][j-1]) j--;
        else i--;

    }
    for (int i=1; i<=d[n][m]; i++)
        fout<<x[i];
}
