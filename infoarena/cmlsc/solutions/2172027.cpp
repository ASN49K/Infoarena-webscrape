#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int nmax = 1029;
int d[nmax][nmax], s1[nmax], s2[nmax], sol[nmax];

int main()
{
    int n,m,i,j,nrs=0;
    f >> m >> n;
    for(i=1; i<=m; ++i)
        f>>s1[i];
    for(i=1; i<=n; ++i)
        f>>s2[i];
    for(i=1; i<=m; ++i)
        for(j=1; j<=n; ++j)
            if(s1[i]==s2[j]) d[i][j] = d[i-1][j-1]+1;
            else d[i][j] = max(d[i][j-1],d[i-1][j]);
    i=m, j=n;
    while(i)
        if (s1[i]==s2[j])
            sol[++nrs] = s1[i], --i, --j;
        else if (d[i-1][j]<d[i][j-1]) --j;
        else --i;
    g<<nrs<<"\n";
    for(i=nrs; i; --i)
        g<<sol[i]<<' ';
    return 0;
}
