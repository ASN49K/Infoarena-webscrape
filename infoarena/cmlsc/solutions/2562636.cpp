#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX=1030;
int n,m,i,j,a[MAX],b[MAX],mat[MAX][MAX],cnt=1;

int main()
{
    ios_base::sync_with_stdio(false);
    fin >> n >> m;
    for(i=1;i<=n;i++)
        fin >> a[i];
    for(j=1;j<=m;j++)
        fin >> b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    fout << mat[n][m] << '\n';
    for(j=1;j<=m;j++)
        if(mat[n][j]==cnt)
            cnt++, fout << b[j] << " ";
    return 0;
}
