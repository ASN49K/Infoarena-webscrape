#include <fstream>

using namespace std;

int mat[1026][1026],a[1026],b[1026];

void backtrack(int i,int j)
{
    if (mat[i][j]==mat[i-1][j])
        return backtrack(i-1,j);
    if (mat[i][j]==mat[i][j-1])
        return backtrack(i,j-1);
    b[mat[i][j]]=a[i];
    return backtrack(i-1,j-1);
}

int main()
{
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
                mat[i][j]=mat[i-1][j-1];
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    backtrack(n,m);
    for (int i=1;i<=mat[n][m];i++)
        fout<<b[i]<<' ';
}
