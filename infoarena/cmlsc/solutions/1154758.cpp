#include <fstream>

using namespace std;

int a[1025],b[1025],v[1025],mat[1025][1025],n,m,i,nre,nr[1025][1025],j;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>a[i];
    for (i=1;i<=m;i++)
        f>>b[i];
    nre=0;
    for (i=1;i<=n;i++)
    {
        if (b[1]==a[i])
            {
                mat[1][i]=mat[1][i-1]+1;
                nre++;
                v[nre]=a[i];
            }
        else
            mat[1][i]=mat[1][i-1];
    }

    for (i=1;i<=m;i++)
    {
        if (b[i]==a[1])
            {
                mat[i][1]=mat[i-1][1]+1;
                nre++;
                v[nre]=b[i];
            }
        else
            mat[i][1]=mat[i-1][1];
    }

    for (i=2;i<=n;i++)
        for (j=2;j<=m;j++)
        {
            if (a[i]==b[j])
                {
                    mat[i][j]=mat[i-1][j-1]+1;
                    nr[i][j]=3;
                    nre++;
                    v[nre]=a[i];
                }
            else
            {
                mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
                if (mat[i][j-1]>mat[i-1][j])
                {
                    mat[i][j]=mat[i][j-1];
                    nr[i][j]=2;
                }
                else
                {
                    mat[i][j]=mat[i-1][j];
                    nr[i][j]=1;
                }
            }
        }
    g<<nre<<'\n';
    for (i=1;i<=nre;i++)
        g<<v[i]<<" ";
    return 0;
}
