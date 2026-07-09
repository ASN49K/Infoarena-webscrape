#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int i, n, m, j, U[1050][1050];
int H[1050], V[1050];

int main()
{
    fin>>n>>m;
    for (i=1; i<=n; i++)
        fin>>H[i];
    for (i=1; i<=m; i++)
        fin>>V[i];
    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
            if (V[i]==H[j])
                U[i][j]=U[i-1][j-1]+1;
            else
                U[i][j]=max(U[i-1][j], U[i][j-1]);
        }
    }
    fout<<U[m][n];
    return 0;
}
