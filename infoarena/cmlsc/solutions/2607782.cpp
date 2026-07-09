#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025];
int lcs[1030][1030];

int main()
{
    int i, j, n, m, lgrez=0;

    fin >> n >> m;
    for(i=1; i<=n; ++i)
        fin >> a[i];
    for(i=1; i<=m; ++i)
        fin >> b[i];
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            if(a[i]==b[j])
            {
                lcs[i][j]=1+max(lcs[i-1][j], lcs[i][j-1]);
            }
            else
                lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
        }
    fout << lcs[n][m] << '\n';
    return 0;
}
