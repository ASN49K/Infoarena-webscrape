#include <fstream>

using namespace std;

ifstream in("clmsc.in");
ofstream out("clmsc.out");

int mat[1100][1100];
int a[1100], b[1100];
int vec[1100];

int main()
{
    int n, m, k=0;
    in>>n>>m;

    for(int i=1; i<=n; i++)
        in>>a[i];
    for(int j=1; j<=m; j++)
        in>>b[j];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                mat[i][j]=mat[i-1][j-1]+1;
                vec[++k]=b[j];
            }

            else
                mat[i][j]=max(mat[i][j-1], mat[i-1][j]);
        }

    out<<mat[n][m]<<'\n';
    for(int i=1; i<=k; i++)
        out<<vec[i]<<" ";

    in.close();
    out.close();
    return 0;
}
