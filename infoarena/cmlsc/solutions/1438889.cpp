#include <fstream>
#define maxn 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, a[maxn], b[maxn], d[maxn][maxn], c[maxn];

int main()
{
    fin >> m >> n;

    for(int i=1; i<=m; i++)
    {
        fin >> a[i];
    }
    for(int i=1; i<=n; i++)
    {
        fin >> b[i];
    }

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i][j-1], d[i-1][j]);
            }
        }
    }

    int ans=d[m][n];
    fout << ans << '\n';

    int l=0;
    for(int i=m; i; i--)
    {
        for(int j=n; j; j--)
        {
            if(a[i]==b[j] && d[i][j]==ans)
            {
                ans--;
                c[l++]=a[i];
            }
        }
    }

    while(l--)
    {
        fout << c[l] << ' ';
    }

    return 0;
}
