#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1<<10],b[1<<10],mat[1<<10][1<<10
],m,n;
void re(int i,int j)
{if(mat[i][j]==0)
  return;
    if(a[i]==b[j])
    {
        re(i-1,j-1);
        fout<<a[i]<<' ';
    }
    else
    {
        if(max(mat[i-1][j],mat[i][j-1])==mat[i-1][j])
        {
            re(i-1,j);
        }
        else
         if(max(mat[i-1][j],mat[i][j-1])==mat[i][j-1])
        {
            re(i,j-1);
        }
    }
}
int main()
{
    fin>>m>>n;
    int i,j;
    for(i=1; i<=m; i++)
        fin>>a[i];
    for(j=1; j<=n; j++)
        fin>>b[j];
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    fout<<mat[m][n]<<'\n';
re(m,n);

    return 0;
}
