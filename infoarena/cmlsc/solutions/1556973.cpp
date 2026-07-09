#include <fstream>
#define NM 1035

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[NM], m, i;
int b[NM], n, j;
int v[NM][NM];

int main()
{
    fin >> m >> n;
    for (i=1; i<=m; i++)
      fin >> a[i];
    for (i=1; i<=n; i++)
      fin >> b[i];
    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
            if (a[i]==b[j])
              v[i][j]=max(max(v[i-1][j], v[i][j-1]), v[i-1][j-1]+1);
            else
              v[i][j]=max(max(v[i-1][j], v[i][j-1]), v[i-1][j-1]);
        }
    }
    fout << v[m][n] << '\n';
    fin.close();
    fout.close();
    return 0;
}
