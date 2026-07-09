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
            if(A[i]==B[j])
            {
                mat[i][j]=mat[i-1][j-1]+1;
                stp=mat[i][j];
                poz[stp].val=j;
                ok=1;
            }
            else
                mat[i][j]=max(mat[i][j-1],mat[i-1][j]);

        }
        if(ok==1)
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
