#include <fstream>

using namespace std;

int main()
{
    int m,n,a[1025],b[1025],i,j,v[1025][1025]={0},k=1;
    ifstream f ("cmlsc.in");
    ofstream g ("cmlsc.out");
    f>>m>>n;
    for (i=1;i<=m;i++)
        f>>a[i];
    for (i=1;i<=n;i++)
        f>>b[i];
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            if (a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                if (v[i-1][j]>=v[i][j-1])
                    v[i][j]=v[i-1][j];
                else
                    v[i][j]=v[i][j-1];
    g<<v[m][n]<<endl;
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            if (v[i][j]==k)
            {
                g<<a[i]<<" ";
                k++;
            }
    f.close ();
    g.close ();
    return 0;
}
