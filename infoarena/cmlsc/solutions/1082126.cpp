# include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n, a[1025], b[1025], i, j, mat[1025][1025], v[1025], k;
int main ()
{
    f>>m>>n;

    for(i=1; i<=m; i++)
    f>>a[i];

    for(j=1; j<=n; j++)
    f>>b[j];

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i-1][j], mat[i][j-1]);

    i=m; j=n;
    while(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            v[++k]=a[i];
            --i;
            --j;
        }
        else if(mat[i-1][j]<mat[i][j-1]) --j;
                else --i;
    }

    g<<k<<"\n";
    for(i=k; i>=1; --i)
    g<<v[i]<<" ";
}
