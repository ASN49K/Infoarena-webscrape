#include <fstream>
using namespace std;

#define NMax 1030

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,k;
int v[NMax],w[NMax];
int sol[NMax];
int M[NMax][NMax];

int main()
{
    int i,j;

    f>>n>>m;
    for(i=1;i<=n;++i) f>>v[i];
    for(i=1;i<=m;++i) f>>w[i];

    for(i=1;i<=n;++i) for(j=1;j<=m;++j)
        if(v[i]==w[j]) M[i][j] = 1 + M[i-1][j-1];
        else M[i][j] = max(M[i-1][j],M[i][j-1]);

    g<<M[n][m]<<"\n";

    i=n; j=m;
    while(k<M[n][m])
    {
        if(v[i]==w[j])
        {
            sol[++k] = v[i];
            --i; --j;
        }
        else
        {
            if(M[i-1][j]>M[i][j-1]) --i;
            else --j;
        }
    }

    for(i=k;i>=1;--i) g<<sol[i]<<" "; g<<"\n";

    f.close();
    g.close();
    return 0;
}
