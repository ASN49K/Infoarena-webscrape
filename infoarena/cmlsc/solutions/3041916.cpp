#include <fstream>

using namespace std;
int n,m,v[2001],w[2001],sir[2001],d[2001][2001];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main(){
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>v[i];
        for(int j=1;j<=m;j++)
            fin>>w[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(v[i]==w[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
    int best=0;
    for(int i=n,j=m;i;)
        if(v[i]==w[j])
            sir[++best]=v[i],i--,j--;
        else if (d[i-1][j] < d[i][j-1])
            j--;
        else
            i--;
    fout<<best<<'\n';
    for(int i=best;i>=1;i--)
        fout<<sir[i]<<" ";
    return 0;
}
