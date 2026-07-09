#include <fstream>
using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int const N=1025;
int x[N],y[N],mat[N][N],v[N];

int max(int a,int b)
{
    if(a>b) return a;
    return b;
}

int main()
{
    int i,j,m,n,r=0;
    in>>m>>n;
    for(i=1;i<=m;i++)
        in>>x[i];
    for(i=1;i<=n;i++)
        in>>y[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(x[i]==y[j]) mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    for (i = m, j = n; i && j;)
        if (x[i] == y[j])
            v[++r] = x[i], --i, --j;
        else
            if (mat[i-1][j] < mat[i][j-1])
                --j;
            else
                --i;
    out<<r<<"\n";
    for(i=r;i>=1;i--)
        out<<v[i]<<" ";
    return 0;
}
