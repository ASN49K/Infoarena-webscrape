#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, cnt, k;
int a[1025], b[1025], v[1025];
int d[1025][1025];

int main ()
{
     in>>n>>m;
     for (int i=1; i<=n; i++)
        in>>a[i];

    for (int i=1; i<=m; i++)
        in>>b[i];

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
                v[++cnt] = a[i];
            }
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
        }
    }


    out<<d[n][m]<<'\n';

    for (int i=1; i<=d[n][m]; i++)
        out<<v[i]<<' ';

    return 0;
}
