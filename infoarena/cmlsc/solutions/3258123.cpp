#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int A[1025],B[1025],mat[1025][1025],v[1025];
int main()
{
    int n,m;
    fin>>n>>m;

    for(int i=1;i<=n;i++)
        fin>>A[i];

    for(int i=1;i<=m;i++)
        {fin>>B[i];}

    if(m>n)
    {
        for(int j=1;j<=m;j++)
        {
            for(int i=1;i<=n;i++)
            {
                if(A[i]==B[j])
                    mat[i][j]=mat[i-1][j]+1;
                else
                    mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
            }
        }

        fout<<mat[n][m]<<'\n';
    }
    else
    {
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=m;i++)
            {
                if(A[j]==B[i])
                    mat[i][j]=mat[i-1][j]+1;
                else
                    mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
            }
        }
        fout<<mat[m][n]<<'\n';
    }
}
