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

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int y=0;
            if(A[i]==B[j])
            {
                if(y==0)
                    mat[i][j]=mat[i-1][j-1]+1,y=1;
                else
                    mat[i][j]=max(mat[i-1][j],mat[i][j-1])+1;
            }

            else
                mat[i][j]=max(mat[i][j-1],mat[i-1][j]);

            if(i==n&&mat[i][j]!=mat[i][j-1])
            {
                int stp=mat[i][j];
                v[stp]=B[j];
            }
        }

    fout<<mat[n][m]<<'\n';
    for(int i=1;i<=mat[n][m];i++)
        fout<<v[i]<<' ';
}
