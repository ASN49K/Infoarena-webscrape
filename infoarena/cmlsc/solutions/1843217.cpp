#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,i,j,k,z[1030],a[1030],b[1030],d[1030][1030];

int main()
{
    fin >> n >> m;
    for(i=1;i<=n;++i) fin >> a[i];
    for(j=1;j<=m;++j) fin >> b[j];

    for (i=1;i<=n;++i)
    {
        for (j=1;j<=m;++j)
        {
            if (a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }

    i=n; j=m;

    while (i && j)
    {
        if (a[i]==b[j])
        {
            z[++k]=a[i];
            --i;
            --j;
        }
        else
        {
            if (d[i-1][j]<d[i][j-1])
            {
                --j;
            }
            else --i;
        }
    }
    fout << k <<'\n';
    for (i=k;i>=1;--i) fout << z[i] << ' ' ;

    return 0;
}
