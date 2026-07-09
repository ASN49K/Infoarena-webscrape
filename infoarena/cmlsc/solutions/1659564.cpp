#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int mat[1026][1026],i,j,m,n,A[1026],B[1026];
void cauta(int q,int t,int v)
{
    if(v>0)
    {
        while(mat[q][t]==mat[q-1][t]||mat[q][t]==mat[q][t-1])
            if(mat[q][t]==mat[q-1][t]) q--;
                else t--;

    cauta(q-1,t-1,v-1);
    fout<<B[q]<<' ';}
}
int main()
{
    fin>>m>>n;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            mat[i][0]=0;
            mat[0][j]=0;
    for(j=1;j<=m;j++)
        fin>>A[j];
    for(i=1;i<=n;i++)
        fin>>B[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(A[j]==B[i]) mat[i][j]=mat[i-1][j-1]+1;
                else if (mat[i-1][j]>mat[i][j-1]) mat[i][j]=mat[i-1][j];
                        else mat[i][j]=mat[i][j-1];

    fout<<mat[n][m]<<'\n';
   cauta(n,m,mat[n][m]);




    return 0;
}
