#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short n,m,v[1025],a[1025],b[1025],LCS[1025][1025];
int main()
{
    short i,j,nr=0;
    fin>>n>>m;
    for(i=1; i<=n; ++i) fin>>a[i];
    for(i=1; i<=m; ++i) fin>>b[i];
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(a[i]==b[j])
                LCS[i][j]=1+LCS[i-1][j-1];
            else
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
    fout<<LCS[n][m]<<'\n';

    i=n;
    j=m;
    while(i>0 && j>0)
    {
        while(LCS[i-1][j]==LCS[i][j]) --i;
        while(LCS[i][j-1]==LCS[i][j]) --j;
        --i,--j;
        v[++nr]=a[i+1];
    }
    for(i=nr; i>=1; --i)
        fout<<v[i]<<' ';
    return 0;
}
