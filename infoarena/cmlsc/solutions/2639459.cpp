#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,k;
int vi[1030],vj[1030],mat[1030][1030],vpoz[1030];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>vi[i];
    for(j=1;j<=m;j++) fin>>vj[j];
    for(j=1;j<=m;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(vj[j]!=vi[i])
                mat[j][i]=max(mat[j-1][i],mat[j][i-1]);
            else
                mat[j][i]=mat[j-1][i-1]+1;
        }
    }
    fout<<mat[m][n]<<'\n';
    j=m;
    i=n;
    while(mat[j][i]!=0)
    {
        if(mat[j][i]>mat[j-1][i] and mat[j][i]>mat[j][i-1])
            vpoz[++k]=i,i--,j--;
        else
        {
            if(mat[j-1][i]>=mat[j][i-1]) j--;
            else i--;
        }
    }
    for(i=k;i>=1;i--)
        fout<<vi[vpoz[i]]<<" ";
    return 0;
}
