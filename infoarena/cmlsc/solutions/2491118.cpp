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
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i][j-1], mat[i-1][j]);
        }

    int i=n, j=m;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            vec[++k]=a[i];
            i--;
            j--;
        }
        else if(mat[i-1][j]>mat[i][j-1])i--;
        else j--;
    }

    out<<k<<'\n';

    for(i=k; i>=1; i--)
        out<<vec[i]<<" ";

    in.close();
    out.close();
    return 0;
}
