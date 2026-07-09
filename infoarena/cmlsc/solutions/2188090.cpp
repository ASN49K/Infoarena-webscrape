#include <iostream>
#include <fstream>

using namespace std;

int mat[1026][1026],a[1026],b[1026];

/*void backtrack(int i,int j)
{
    if (mat[i][j]==0)
        return;
    if (mat[i][j]==mat[i-1][j])
        return backtrack(i-1,j);
    if (mat[i][j]==mat[i][j-1])
        return backtrack(i,j-1);
    b[mat[i][j]]=a[i];
    return backtrack(i-1,j-1);
}*/

int main()
{
    //ifstream fin ("/Users/biroiani/Documents/INFO/Cmlsc/cmlsc.in");
    //ofstream fout ("/Users/biroiani/Documents/INFO/Cmlsc/cmlsc.out");
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    int n,m,i,j;
    fin>>n>>m;
    for (i=1;i<=n;i++)
        fin>>a[i];
    for (i=1;i<=m;i++)
        fin>>b[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
            cout<<mat[i][j]<<' ';
        cout<<'\n';
    }
    //backtrack(n,m);
    i=n;
    j=m;
    while (mat[i][j]>0)
    {
        if (mat[i][j]==mat[i-1][j])
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
}
