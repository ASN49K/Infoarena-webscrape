#include<fstream>
#define nmax (1<<10)+10
using namespace std;
int N,M;
int i,j,A[nmax],B[nmax],D[nmax][nmax],nr,sir[nmax];
int max(int a, int b)
{
    return a>b?a:b;
}
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    f>>N>>M;
    for (i=1; i<=N; ++i)
        f>>A[i];
    for (i=1; i<=M; ++i)
        f>>B[i];
    for (i=1; i<=N; ++i)
        for (j=1; j<=M; ++j)
            if (A[i]==B[j])
                D[i][j]=1+D[i-1][j-1];
            else
                D[i][j]=max(D[i-1][j],D[i][j-1]);
    nr=0;
    j=M;
    i=N;
    while (i && j)
    {
        if (A[i]==B[j])
            sir[++nr]=A[i],
                      i--,
                      j--;
        else if (D[i-1][j]>D[i][j-1])
            i--;
        else
            j--;
    }
    g<<nr<<'\n';
    for (i=nr; i>=1; --i)
        g<<sir[i]<<' ';
    return 0;
}
