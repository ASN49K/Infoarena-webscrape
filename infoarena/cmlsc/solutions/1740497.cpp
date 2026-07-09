#include <fstream>

using namespace std;
ofstream fout("cmlsc.out");
ifstream fin("cmlsc.in");

int n,m,v[1030],v1[1030],a[1030][1030],i,j,sir[1030],k,b;

int main()
{
    //citesc cele doua siruri

    fin>>n>>m;

    for(i=1;i<=n;i++)
    {
        fin>>v[i];
    }

    for(i=1;i<=m;i++)
    {
        fin>>v1[i];
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v[i]==v1[j])
            {
                a[i][j]=a[i-1][j-1]+1;
            }

            else
            {
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }

    fout<<a[n][m]<<'\n';

    b=1;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i][j]!=a[i-1][j] && a[i][j]!=a[i][j-1] && a[i][j]==b)
            {
                sir[++k]=v[i];
                b++;
            }
        }
    }

    for(i=1;i<=k;i++)
    {
        fout<<sir[i]<<" ";
    }

    return 0;
}
