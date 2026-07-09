#include <fstream>

using namespace std;

int mat[1069][1069], v1[1069], v2[1069], apar1[1069], apar2[1069], sol[1069], k;

int main()
{
    ifstream in ("cmlsc.in");
    ofstream out ("cmlsc.out");
    int n, m, i, j;
    in>>n>>m;
    for (i=1; i<=n; i++)
        in>>v1[i];
    for (i=1; i<=m; i++)
        in>>v2[i];
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            if (mat[i-1][j]>=mat[i][j-1])
                mat[i][j]=mat[i-1][j];
            else
                mat[i][j]=mat[i][j-1];
            if (v1[i]==v2[j] && apar1[i]==0 && apar2[j]==0)
            {
                mat[i][j]++;
                apar1[i]=1;
                apar2[j]=1;
            }
        }
    }
    i=n; j=m;
    while (1)
    {
        while (mat[i][j]==mat[i-1][j] && i>1)
            i--;
        while (mat[i][j]==mat[i][j-1] && j>1)
            j--;
        sol[++k]=v1[i];
        if (i>1) i--;
        if (j>1) j--;
        if (i<=1 && j<=1)
            break;
    }
    out<<k<<"\n";
    for (i=k; i>=1; i--)
        out<<sol[i]<<" ";
    return 0;
}

