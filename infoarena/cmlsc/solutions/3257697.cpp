#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int A[1025],B[1025],mat[1025][1025];
int main()
{
    int n,m;
    fin>>n>>m;

    for(int i=1;i<=n;i++)
        fin>>A[i];

    for(int i=1;i<=m;i++)
        {fin>>B[i];}


        int cnt=0;
        for(int j=1;j<=m;j++)
            for(int i=1;i<=n;i++)
                if(A[i]==B[j])
                {
                    mat[i][j]=A[i];
                    if(i==n)
                        cnt++;
                }
                else
                {
                    if(i==1)
                        mat[i][j]=-1;
                    else
                    {
                        mat[i][j]=mat[i-1][j];
                        if(i==n&&mat[i][j]!=-1)
                            cnt++;
                    }

                }
        fout<<cnt<<'\n';
        for(int i=1;i<=m;i++)
            if(mat[n][i]!=-1)
                fout<<mat[n][i]<<' ';
}
