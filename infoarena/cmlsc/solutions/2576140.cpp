#include <fstream>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int d[1050][1050], a[1050], b[1050], nr, n, m, sol[1050];

int main()
{
    int i, j;

    fin>>n>>m;

    for (i=1; i<=n; i++)
        fin>>a[i];
    for (i=1; i<=m; i++)
        fin>>b[i];

    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            if (a[i]==b[j])
            {
                d[i][j]=1+d[i-1][j-1];
            }
            else
            {
                if (d[i][j-1]>d[i-1][j])
                {
                    d[i][j]=d[i][j-1];
                }
                else
                {
                    d[i][j]=d[i-1][j];
                }
            }
        }
    }
    nr=d[n][m];

    fout<<nr<<'\n';

    for (i=n; i>=1; i--)
    {
        for (j=m; j>=1; j--)
        {
            if (a[i]==b[j] && d[i][j]==nr)
            {
                sol[nr]=a[i];
                nr--;
            }
        }
    }

    for (i=1; i<=d[n][m]; i++)
    {
        fout<<sol[i]<<" ";
    }

    fin.close();
    fout.close();
    return 0;
}
