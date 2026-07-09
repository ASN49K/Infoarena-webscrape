#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
struct y{int val,val_ant;};
int A[1025],B[1025],mat[1025][1025],v[1025];
y poz[1025];
int main()
{
    int n,m,stp=0;
    fin>>n>>m;

    for(int i=1;i<=n;i++)
        fin>>A[i];

    for(int i=1;i<=m;i++)
        {fin>>B[i];}

    for(int i=1;i<=n;i++)
    {
        int ok=0;
        for(int j=1;j<=m;j++)
        {
            int y=0;
            if(A[i]==B[j])
            {
                if(y==0)
                {
                    mat[i][j]=mat[i-1][j-1]+1,y=1;
                    poz[mat[i][j]].val=j;
                }

                else
                    mat[i][j]=max(mat[i-1][j],mat[i][j-1])+1;
                ok=1;
            }
            else
                mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
            stp=mat[i][j];
        }
        if(ok)
        {
            if((poz[stp].val<poz[stp].val_ant)||poz[stp].val_ant==0)
                v[stp]=A[i];

            poz[stp].val_ant=poz[stp].val;
        }

    }


    fout<<mat[n][m]<<'\n';
    for(int i=1;i<=mat[n][m];i++)
        fout<<v[i]<<' ';
}
