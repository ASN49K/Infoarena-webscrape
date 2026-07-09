#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,best[1030][1030],a[1030][1030];
int main()
{
    f>>m>>n;
    int i,j;
    for(i=1;i<=m;i++)
        f>>a[0][i];
    for(i=1;i<=n;i++)
        f>>a[1][i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            best[i][j]=max(best[i][j-1],best[i-1][j]);
            if(a[0][i]==a[1][j])
                best[i][j]=best[i-1][j-1]+1;
        }
	g<<best[m][n]<<'\n';
    return 0;
}
