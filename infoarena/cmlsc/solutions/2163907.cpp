#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n, m, i, a[1030], b[1030], mat[1030][1030], j, fin[1030], nr;
int main()
{
    in>>m>>n;
    for(i=1; i<=m; ++i)
        in>>a[i];
    for(i=1; i<=n; ++i)
        in>>b[i];
    for(i=1; i<=m; ++i)
    {
        for(j=1; j<=n; ++j)
        {
            if(a[i]==b[j])
            {
                mat[i][j]=mat[i-1][j-1]+1;
            }
            else
            {
                if(mat[i][j-1]>mat[i-1][j])
                    mat[i][j]=mat[i][j-1];
                else
                    mat[i][j]=mat[i-1][j];
            }
        }
    }
    out<<mat[m][n]<<"\n";
    for(i=n, j=m; i>0 && j>0;)
    {
        if (a[i]==b[j])
        {
            fin[++nr]=a[i];
            j--;
            i--;
        }
        else
            if (mat[i-1][j]> mat[i][j-1])
                i--;
            else
                j--;
    }
    for(i=nr; i>=1; --i)
        out<<fin[i]<<" ";
    return 0;
}
