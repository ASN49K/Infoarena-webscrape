#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int A[1025],B[1025],mat[1025][1025],v[1025];
int main()
{
    int n,m,idx_max=-1,pozi,pozj,cnt=0;
    fin>>n>>m;

    for(int i=1;i<=n;i++)
        fin>>A[i];

    for(int i=1;i<=m;i++)
        {fin>>B[i];}

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[i]==B[j])
            {
                mat[i][j]=mat[i-1][j-1]+1;
                if(mat[i][j]>=idx_max)
                {
                    idx_max=mat[i][j];
                    pozi=i;
                    pozj=j;
                    v[idx_max]=A[i];
                }
            }
            else
                mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
        }
    }

    fout<<mat[n][m]<<'\n';

    for(int i=pozi;i>=1;i--)
        for(int j=pozj;j>=1;j--)
        {
            if(A[i]==B[j]&&mat[i][j]==idx_max)
            {
                v[++cnt]=A[i];
                idx_max--;
            }

        }
    for(int i=cnt;i>=1;i--)
        fout<<v[i]<<' ';
}
