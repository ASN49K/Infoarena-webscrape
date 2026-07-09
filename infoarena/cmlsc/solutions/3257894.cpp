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


        int y=0;
        for(int j=1;j<=m;j++)
            for(int i=1;i<=n;i++)
                {
                    if(j==1)
                    {
                        if(i==1)
                            mat[i][j]=-1;
                        else
                        {
                            if(A[i]==B[j])
                                mat[i][j]=A[i];
                            else
                                mat[i][j]=mat[i-1][j];
                        }

                    }
                    else
                    {
                        if(A[i]==B[j])
                        {
                            mat[i][j]=A[i];
                            y=1;
                        }
                        else
                        {
                            if(y==0)
                                mat[i][j]=mat[i][j-1];
                            else
                                mat[i][j]=mat[i-1][j];
                        }
                    }
                    if(i==n)
                        y=0;
                }
                int cnt=0,v[1025];
        for(int i=1;i<=n;i++)
            if(mat[i][m]!=-1&&mat[i][m]!=mat[i-1][m])
                    v[++cnt]=mat[i][m];
        fout<<cnt<<'\n';
        for(int i=1;i<=cnt;i++)
            fout<<v[i]<<' ';

}
