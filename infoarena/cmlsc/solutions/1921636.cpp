#include <fstream>
#define smax 1030

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int maxim(int a, int b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    int i, j, m, n, V[smax][smax], A[smax], B[smax], k;
    f>>m>>n;
    for (i=1;i<=m;i++)
        f>>A[i];
    for (i=1;i<=n;i++)
        f>>B[i];
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            if (A[i]==B[j])
                V[i][j]=1+V[i-1][j-1];
            else
                V[i][j]=maxim(V[i-1][j],V[i][j-1]);
    k=V[m][n];
    g<<k<<endl;
    for (i=1;i<=m&&k>0;i++)
        for (j=1;j<=n&&k>0;j++)
        if(A[i]==B[j])
        {
            g<<A[i]<<" ";
            k--;
        }
        f.close();
        g.close();
}
