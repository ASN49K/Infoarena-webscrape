#include <fstream>
#define MAXN 1024
using namespace std;

ofstream g("cmlsc.out");
int n,m,a[MAXN],b[MAXN],solutie[MAXN][MAXN];

void subsir(int i,int j)
{
    if (i<=n && j<=m )
    {
        if (a[i]==b[j])
        {
            g<<a[i]<<' ';
            subsir(i+1,j+1);
        }
        else
        {
            if (solutie[i+1][j]>solutie[i][j+1])
                subsir(i+1,j);
            else
                subsir(i,j+1);
        }
    }
    return;
}

int main()
{
    int i,j;
    ifstream f("cmlsc.in");
    f>>n>>m;
    for (i=1;i<=n+m;i++)
        if (i<=n)
            f>>a[i];
        else
            f>>b[i-n];
    for(i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        {
            if (a[i]==b[j])
                solutie[i][j]=solutie[i-1][j-1]+1;
            else
                if (solutie[i-1][j]>solutie[i][j-1])
                    solutie[i][j]=solutie[i-1][j];
                else
                    solutie[i][j]=solutie[i][j-1];
        }
    g<<solutie[n][m]<<'\n';
    subsir(1,1);
    f.close();
    g.close();
    return 0;
}
