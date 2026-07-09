#include <fstream>
#define N 1030

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m;
int mat[N][N];
int a[N], b[N];
int sir[N];

int main()
{
    in>>n>>m;

    for(int i=1; i<=n; ++i)
        in>>a[i];

    for(int j=1; j<=m; ++j)
        in>>b[j];

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }

    int best=0;
    for(int i=n, j=m; i>0;)
    {
        if(a[i]==b[j])
            sir[++best]=a[i], --i, --j;
        else if(mat[i-1][j]<mat[i][j-1])
            j--;
        else i--;
    }

    out<<best<<'\n';
    for(int i=best; i>=1; --i)
    {
        out<<sir[i]<<" ";
    }

    in.close();
    out.close();
    return 0;
}
