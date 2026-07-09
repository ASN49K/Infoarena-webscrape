#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,A[101],B[101],M[101][101];

int cmlsc(int n, int A[101], int m, int B[101], int M[101][101])
{
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(A[i]==B[j])
                M[i][j]=1+M[i-1][j-1];
            else
                M[i][j]=max(M[i-1][j],M[i][j-1]);
    return M[n][m];
}

void afis(int n, int A[101], int m, int B[101], int M[101][101])
{
    int subsir[101],k=0,i,j;
    for (i = n, j = m; i; )
        if (A[i] == B[j])
            subsir[++k] = A[i], --i, --j;
        else if (M[i-1][j] < M[i][j-1])
            --j;
        else
            --i;
    for(i=k; i>=1; i--)
        g<<subsir[i]<<' ';
    g<<'\n';
}

int main()
{
    int i,j;
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>A[i];
    for(i=1; i<=m; i++)
        f>>B[i];
    g<<cmlsc(n,A,m,B,M)<<'\n';
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
            g<<M[i][j]<<' ';
        g<<'\n';
    }
    afis(n,A,m,B,M);
    return 0;
}
