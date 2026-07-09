#include <iostream>
#include <fstream>

using namespace std;

int mat[1026][1026],a[1026],b[1026];

int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    int n,m;
    fin>>n>>m;
    for (int i=1;i<=n;i++)
    fin>>a[i];
    for (int j=1;j<=m;j++)
    fin>>b[j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
            mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    int i=n,j=m;
    while (mat[i][j]!=0)
    {
        if(mat[i][j]==mat[i-1][j])
            i--;
        else if (mat[i][j]==mat[i][j-1])
            j--;
        else
        {
            b[mat[i][j]]=a[i];
            i--;
            j--;
        }
    }
    fout<<mat[n][m]<<'\n';
    for (int i=1;i<=mat[n][m];i++)
    fout<<b[i]<<' ';
    return 0;
}
