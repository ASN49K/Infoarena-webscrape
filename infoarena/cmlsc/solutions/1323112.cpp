#include <fstream>
#define N 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,v[N],w[N],D[N][N],sir[N],x=0;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>v[i];
    for(i=1;i<=m;i++)
        fin>>w[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(v[i]==w[j])
                D[i][j]=1+D[i-1][j-1];
            else
                D[i][j]=max(D[i][j-1],D[i-1][j]);
        }
    for(i=n,j=m;i;)
    {
        if(v[i]==w[j])
        {
            sir[x++]=v[i];
            i--;
            j--;
        }
        else if(D[i-1][j]<D[i][j-1])
                j--;
            else
                i--;
    }
    fout<<x<<'\n';
    for(i=x-1;i>=0;i--)
        fout<<sir[i]<<" ";
    fin.close();
    fout.close();
    return 0;
}
