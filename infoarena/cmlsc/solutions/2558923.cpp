#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1029],b[1029];
int mat[1029][1029];

int n,m;

void Read()
{
    int i,j;
    int sir[1096], ct = 0;
    fin>>n>>m;
    for(i=1; i<=n; ++i)
    {
        fin>>a[i];
    }
    for(i=1; i<=m; ++i)
        fin>>b[i];
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(a[i] == b[j])
                mat[i][j] = 1 + mat[i-1][j-1];
            else mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
    fout<<mat[n][m]<<"\n";
    for(i = n,j=m; i>=1;)
            if(a[i] == b[j])
            {
                sir[++ct] = a[i];
                i--;
                j--;
            }
            else if( mat[i-1][j] < mat[i][j-1] )
                    j--;
                 else i--;
    for(i=ct; i>=1; --i)
        fout<<sir[i]<<" ";
}

int main()
{
    Read();
    return 0;
}
